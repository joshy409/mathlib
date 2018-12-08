#include "raylib.h"
#include "utils.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "Sprite.h"
#include <string>
#include <vector>
#include <iostream>


int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1856;
	int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	Sprite sprite;
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
	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here

		//sprite.setPos(GetMousePosition());
		sprite.setPos(vec2{ z, 100 * sin(z*DEG2RAD) + screenWidth / 4 });
		z > screenWidth+10 ? z = 0: z+=2;

		if (IsKeyDown(KEY_UP)) {
			radius++;
			radius = clamp<float>(radius, 10, 400);
		}

		if (IsKeyDown(KEY_DOWN)) {
			radius--;
			radius = clamp<float>(radius, 10, 400);
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) ) {
			maxCount++;
			if (maxCount < 21) {
				sprites.push_back(sprite.clone());
			}
			maxCount = clamp<int>(maxCount, 2, 20);
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON )) {
			maxCount--;
			if (maxCount > 0) {
				sprites.pop_back();
			}
			maxCount = clamp<int>(maxCount, 1, 20);
		}

		for (spaceCount; spaceCount < sprites.size(); spaceCount++) {
			sprites[spaceCount].movePos(vec2{ radius * cos((degrees + (spaceCount * (float) 360/maxCount))* DEG2RAD),radius * sin((degrees + (spaceCount * (float) 360/maxCount))* DEG2RAD) });
			degrees++;
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		sprite.draw();
		for (auto &outer : sprites) {
			outer.draw();
			outer.setPos(sprite.getPos());
		}

		DrawText(std::to_string(radius).c_str(), 100, 100, 50, BLACK);
		DrawText(std::to_string(sprites.size()).c_str(), 100, 150, 50, BLACK);


		for (int z = 0; z < screenWidth; z++) {
			DrawPixel(z + sprite.texture.width/2, 100 * sin(z*DEG2RAD) + screenWidth / 4 + sprite.texture.height/2, BLACK);

		}


		EndDrawing();

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