#include "raylib.h"
#include "utils.h"
#include "vec2.h"
#include "transform2d.h"
#include "Sprite.h"
#include <string>
#include <vector>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1856;
	int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(120);
	//--------------------------------------------------------------------------------------
	Sprite tank;
	tank.resetPos();
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

		tank.draw();

		if (IsKeyDown(KEY_LEFT)) {
			tank.transform.localRot -= .5;
		}
		if (IsKeyDown(KEY_RIGHT)) {
			tank.transform.localRot += .5;
		}

		if (IsKeyPressed(KEY_UP)) {
			tank.transform.localScale -= .1;
		}
		if (IsKeyPressed(KEY_DOWN)) {
			tank.transform.localScale += .1;
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}