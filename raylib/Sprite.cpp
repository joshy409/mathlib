#include "Sprite.h"



Sprite::Sprite()
{
	texture = LoadTexture("tank_explosion2.png");
	pos = vec2{ -100,-100 };
}


Sprite::~Sprite()
{
}

void Sprite::draw()
{
	DrawTextureV(texture, pos, WHITE);
}

void Sprite::setPos(const vec2 _pos)
{
	pos = _pos;
}

void Sprite::resetPos()
{
	pos = { (float)1856 / 2,(float)1024 / 2 };
}

vec2 Sprite::getPos()
{
	return pos;
}

void Sprite::movePos(const vec2 _pos)
{
	pos += _pos;
}

void Sprite::moveTowards(const vec2 _pos)
{
	pos += _pos;
	if (pos.x > 1856) {
		pos.x = 0;
	}
	if (pos.x < 0) {
		pos.x = 1856;
	}
	if (pos.y > 1024) {
		pos.y = 0;
	}
	if (pos.y < 0) {
		pos.y = 1024;
	}
}

Sprite Sprite::clone()
{
	return Sprite();
}
