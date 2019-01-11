#include "raylib.h"
#include "utils.h"
#include "vec2.h"
#include "transform2d.h"
#include "Sprite.h"
#include <string>
#include <vector>
#include "ChildSprite.h"

void update(Sprite &tank, float &scale, ChildSprite &cannon, Sprite &tank2, float &scale2, ChildSprite &cannon2)
{
	//tank1
	if (IsKeyDown(KEY_I)) {
		scale += .1;
	}
	if (IsKeyDown(KEY_K)) {
		scale -= .1;
	}
	tank.setScale(scale);

	if (IsKeyDown(KEY_J)) {
		tank.transform.localRot -= .5;
		cannon.transform.localRot -= .5;
	}
	if (IsKeyDown(KEY_L)) {
		tank.transform.localRot += .5;
		cannon.transform.localRot += .5;
	}

	if (IsKeyDown(KEY_Q)) {
		cannon.transform.localRot -= .5;
	}
	if (IsKeyDown(KEY_E)) {
		cannon.transform.localRot += .5;
	}

	if (IsKeyDown(KEY_W)) {
		tank.transform.localPos.y -= 3;
	}
	if (IsKeyDown(KEY_A)) {
		tank.transform.localPos.x -= 3;
	}

	if (IsKeyDown(KEY_S)) {
		tank.transform.localPos.y += 3;
	}
	if (IsKeyDown(KEY_D)) {
		tank.transform.localPos.x += 3;
	}

	//tank2
	if (IsKeyDown(KEY_KP_8)) {
		scale2 += .1;
	}
	if (IsKeyDown(KEY_KP_5)) {
		scale2 -= .1;
	}
	tank2.setScale(scale2);

	if (IsKeyDown(KEY_KP_4)) {
		tank2.transform.localRot -= .5;
	}
	if (IsKeyDown(KEY_KP_6)) {
		tank2.transform.localRot += .5;
	}

	if (IsKeyDown(KEY_KP_7)) {
		cannon2.transform.localRot -= .5;
	}
	if (IsKeyDown(KEY_KP_9)) {
		cannon2.transform.localRot += .5;
	}

	if (IsKeyDown(KEY_UP)) {
		tank2.transform.localPos.y -= 3;
	}
	if (IsKeyDown(KEY_LEFT)) {
		tank2.transform.localPos.x -= 3;
	}

	if (IsKeyDown(KEY_DOWN)) {
		tank2.transform.localPos.y += 3;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		tank2.transform.localPos.x += 3;
	}

}

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(120);
	//--------------------------------------------------------------------------------------
	Sprite tank = { "tank/towerDefense_tile268.png" };
	tank.resetPos();
	ChildSprite cannon = {& tank,"tank/towerDefense_tile291.png" };

	Sprite tank2 = { "tank/towerDefense_tile269.png" };
	tank2.resetPos();
	ChildSprite cannon2 = { &tank2, "tank/towerDefense_tile292.png"  };
	
	float scale = 1;
	float scale2 = 1;
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

		update(tank,scale,cannon,tank2,scale2,cannon2);

		tank.draw();
		cannon.update();
		cannon.draw();

		tank2.draw();
		cannon2.update();
		cannon2.draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}


