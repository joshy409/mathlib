#include "raylib.h"
#include "utils.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "Sprite.h"
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iostream>


int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1856;
	int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	Sprite sprite;
	sprite.setPos(vec2{ (float)screenWidth / 2 , (float)screenHeight / 2 });
	std::vector<Sprite> sprites;
	sprites.push_back(sprite.clone());
	sprites.push_back(sprite.clone());
	sprites.push_back(sprite.clone());
	sprites.push_back(sprite.clone());
	sprites.push_back(sprite.clone());

	float speed = 100;
	float radius = 100;
	int spaceCount = 0;
	int maxCount = 5;
	float degrees = 0;
	float z = 0;
	SetTargetFPS(300);
	seedRand(time(NULL));
	int frames = 0;
	sprite.destination = vec2{ (float)rand(0,screenWidth), (float)rand(0,screenHeight) };
	//--------------------------------------------------------------------------------------

	RenderTexture test = LoadRenderTexture(screenWidth, screenHeight);
	RenderTexture second = LoadRenderTexture(screenWidth, screenHeight);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{

		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here

		//sprite follows the mouse
		/*sprite.setPos(GetMousePosition());
		paths.push_back(sprite.getPos());*/

		//sprite follows a sine wave
		/*sprite.setPos(vec2{ z, 100 * sin(z*DEG2RAD) + screenWidth / 4 });
		paths.push_back(sprite.getPos());
		z > screenWidth+10 ? z = 0: z+=2;*/

		//random sprite position
		if (IsKeyPressed(KEY_ENTER)) {
			sprite.destination = vec2{ (float)rand(0,screenWidth) - screenWidth/2, (float)rand(0,screenHeight)-screenHeight/2 };
		}
		
		//random sprite positon change based on frames
		if (frames > rand(180, 300)) {
			sprite.destination = vec2{ (float)rand(0,screenWidth) - screenWidth / 2, (float)rand(0,screenHeight) - screenHeight / 2 };
			frames = 0;
		}
		frames++;

		//change the radius between orignal and the circle clones
		if (IsKeyDown(KEY_UP)) {
			radius++;
			radius = clamp<float>(radius, 10, 400);
		} else if (IsKeyDown(KEY_DOWN)) {
			radius--;
			radius = clamp<float>(radius, 10, 400);
		}

		//increase or decrease the number of circling clones
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) ) {
			maxCount++;
			if (maxCount < 21) {
				sprites.push_back(sprite.clone());
			}
			maxCount = clamp<int>(maxCount, 2, 20);
		}	else if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON )) {
			maxCount--;
			if (maxCount > 0) {
				sprites.pop_back();
			}
			maxCount = clamp<int>(maxCount, 1, 20);
		}

		//move the clones to circle around the original
		for (spaceCount; spaceCount < sprites.size(); spaceCount++) {
			sprites[spaceCount].movePos(vec2{ radius * cos((degrees + (spaceCount * (float) 360/maxCount))* DEG2RAD),radius * sin((degrees + (spaceCount * (float) 360/maxCount))* DEG2RAD) });
			degrees++;
		}
		//----------------------------------------------------------------------------------

		//move
		sprite.moveTowards(sprite.destination.getNormalized());

		BeginTextureMode(second);
		ClearBackground(BLANK);
		DrawTexture(test.texture, 0, 0, WHITE);
		EndTextureMode();

		BeginTextureMode(test);
		ClearBackground(BLANK);
		DrawTexture(second.texture, 0, 0, WHITE);
		DrawPixel(sprite.getPos().x + sprite.texture.width / 2, sprite.getPos().y + sprite.texture.height / 2, BLACK);
		EndTextureMode();

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawTexture(second.texture, 0, 0, WHITE);

		sprite.draw();
		for (auto &outer : sprites) {
			outer.draw();
			outer.setPos(sprite.getPos());
		}

		DrawText(std::to_string(radius).c_str(), 100, 100, 50, BLACK);
		DrawText(std::to_string(sprites.size()).c_str(), 100, 150, 50, BLACK); 
		DrawText(std::to_string(sprite.destination.x).c_str(), 500, 100, 50, BLACK);
		DrawText(std::to_string(sprite.destination.y).c_str(), 500, 150, 50, BLACK);
		
		//draws sine wave to indicate the path of the sprite
		/*for (int z = 0; z < screenWidth; z++) {
			DrawPixel(z + sprite.texture.width/2, 100 * sin(z*DEG2RAD) + screenWidth / 4 + sprite.texture.height/2, BLACK);
		}*/

		//draws the path the original has travelled
		/*for (auto pos : paths) {
			DrawPixel(pos.x + sprite.texture.width / 2, pos.y + sprite.texture.height / 2, BLACK);
		}*/
		
		EndDrawing();

		//reset parameters
		spaceCount = 0;
		degrees > 360 ? degrees = 0 : degrees *= 1;

		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}