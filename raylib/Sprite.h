#pragma once
#include "raylib.h"
#include "vec2.h"
class Sprite
{
public:
	Sprite();
	~Sprite();

	void draw();
	void setPos(const vec2 _pos);
	void resetPos();
	vec2 getPos();
	void movePos(const vec2 _pos);
	Sprite clone();
	Texture2D texture;

private:
	
	vec2 pos;
};

