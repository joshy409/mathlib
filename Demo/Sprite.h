#pragma once
#include "raylib.h"
#include "transform2d.h"
class Sprite
{
public:
	Sprite();
	Sprite(std::string texturePath);
	~Sprite();

	transform2d transform;
	Rectangle sourceRec;
	Rectangle destRec;
	vec2 origin;

	void draw();
	void setPos(const vec2 _pos);
	void resetPos();
	vec2 getPos();

	void setRotation(const float angle);
	void resetRotation();
	float getRotation();

	void setScale(const float scale);
	void resetScale();
	float getScale();

	void moveTowards(const vec2 _pos);
	Sprite clone();
	Texture2D texture;
	vec2 destination;
};

