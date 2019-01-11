#include "Sprite.h"



Sprite::Sprite()
{
	texture = LoadTexture("tank/towerDefense_tile268.png");
	sourceRec = { 0.0f,0.0f, (float)texture.width, (float)texture.height };
	destRec = { transform.localPos.x , transform.localPos.y , (float)texture.width * transform.localScale  , (float)texture.height * transform.localScale };
	origin = { (float)texture.width * transform.localScale /2.f, (float)texture.height * transform.localScale /2.f };
}

Sprite::Sprite(std::string texturePath)
{
	texture = LoadTexture(texturePath.c_str());
	sourceRec = { 0.0f,0.0f, (float)texture.width, (float)texture.height };
	destRec = { transform.localPos.x , transform.localPos.y , (float)texture.width * transform.localScale  , (float)texture.height * transform.localScale };
	origin = { (float)texture.width * transform.localScale / 2.f, (float)texture.height * transform.localScale / 2.f };
}


Sprite::~Sprite()
{
}

void Sprite::draw()
{
	DrawTexturePro(texture, sourceRec, destRec, origin, transform.localRot, WHITE);
}

void Sprite::setPos(const vec2 _pos)
{
	transform.localPos = _pos;
	destRec = { transform.localPos.x , transform.localPos.y , (float)texture.width * transform.localScale  , (float)texture.height * transform.localScale };
	origin = { (float)texture.width * transform.localScale / 2.f, (float)texture.height * transform.localScale / 2.f };
}

void Sprite::resetPos()
{
	transform.localPos = { (float)1856 / 2,(float)1024 / 2 };
	destRec = { transform.localPos.x , transform.localPos.y , (float)texture.width * transform.localScale  , (float)texture.height * transform.localScale };
	origin = { (float)texture.width * transform.localScale / 2.f, (float)texture.height * transform.localScale / 2.f };
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
	destRec = { transform.localPos.x , transform.localPos.y , (float)texture.width * transform.localScale  , (float)texture.height * transform.localScale };
	origin = { (float)texture.width * (transform.localScale / 2.f), (float)texture.height * (transform.localScale / 2.f) };
}

void Sprite::resetScale()
{
	transform.localScale = 1.f;
	destRec = { transform.localPos.x , transform.localPos.y , (float)texture.width * transform.localScale  , (float)texture.height * transform.localScale };
	origin = { (float)texture.width * transform.localScale / 2.f, (float)texture.height * transform.localScale / 2.f };
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
