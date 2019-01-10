#include "Sprite.h"



Sprite::Sprite()
{
	texture = LoadTexture("tank/towerDefense_tile268.png");
}


Sprite::~Sprite()
{
}

void Sprite::draw()
{
	DrawTextureEx(texture, transform.localPos, transform.localRot, transform.localScale, WHITE);
}

void Sprite::setPos(const vec2 _pos)
{
	transform.localPos = _pos;
}

void Sprite::resetPos()
{
	transform.localPos = { (float)1856 / 2,(float)1024 / 2 };
}

vec2 Sprite::getPos()
{
	return transform.localPos;
}

void Sprite::setRotation(const float angle)
{
	transform.rotate(angle);
}

void Sprite::resetRotation()
{
	transform.localRot = 0.f;
}

float Sprite::getRotation()
{
	return transform.localRot;
}

void Sprite::setScale(const float scale)
{
	transform.scale(scale);
}

void Sprite::resetScale()
{
	transform.localScale = 1.f;
}

float Sprite::getScale()
{
	return transform.localScale;
}

void Sprite::moveTowards(const vec2 _pos)
{
	transform.localPos += _pos;
	if (transform.localPos.x > 1856) {
		transform.localPos.x = 0;
	}
	if (transform.localPos.x < 0) {
		transform.localPos.x = 1856;
	}
	if (transform.localPos.y > 1024) {
		transform.localPos.y = 0;
	}
	if (transform.localPos.y < 0) {
		transform.localPos.y = 1024;
	}
}

Sprite Sprite::clone()
{
	return Sprite();
}
