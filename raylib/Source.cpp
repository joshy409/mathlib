#include "raylib.h"
#include "utils.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include <string>
#include <iostream>
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1856;
	int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	Texture2D sprite = LoadTexture("tank_explosion2.png");
	vec2 pos = { (float)screenWidth/2,(float)screenHeight/2 };
	float speed = 100;
	SetTargetFPS(120);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		vec2 directionToCursor = { GetMousePosition().x - pos.x  , (GetMousePosition().y - pos.y )};
		directionToCursor.normalize();
		pos += directionToCursor * (float)(speed * GetFrameTime());
		
		DrawTexture(sprite, pos.x, pos.y, WHITE);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}