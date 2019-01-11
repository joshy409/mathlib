#include "ChildSprite.h"



ChildSprite::ChildSprite(Sprite* _parent)
{
	parent = _parent;
	transform.localPos = mat3::translation(parent->transform.localPos) * vec2 { 1, 1 };
	texture = LoadTexture("tank/towerDefense_tile291.png");
	sourceRec = { 0.0f,0.0f, (float)texture.width, (float)texture.height };
	destRec = { transform.localPos.x , transform.localPos.y, (float)texture.width * transform.localScale  , (float)texture.height * transform.localScale };
	origin = { (float)texture.width * transform.localScale / 2.f, (float)texture.height * transform.localScale / 2.f };
}

ChildSprite::ChildSprite(Sprite * _parent, std::string texturePath)
{
	parent = _parent;
	transform.localPos = mat3::translation(parent->transform.localPos) * vec2 { 1, 1 };
	texture = LoadTexture(texturePath.c_str());
	sourceRec = { 0.0f,0.0f, (float)texture.width, (float)texture.height };
	destRec = { transform.localPos.x , transform.localPos.y, (float)texture.width * transform.localScale  , (float)texture.height * transform.localScale };
	origin = { (float)texture.width * transform.localScale / 2.f, (float)texture.height * transform.localScale / 2.f };
}

void ChildSprite::update()
{
	mat3 childTSMatrix = mat3{ 1,0,0,0,1,0,0,0,1 } * parent->transform.getTSMatrix();
	transform.localPos = vec2{ childTSMatrix.z1,childTSMatrix.z2 };
	transform.localScale = childTSMatrix.x1;
	
	
	destRec = { transform.localPos.x , transform.localPos.y, (float)texture.width * transform.localScale  , (float)texture.height * transform.localScale };
	origin = { (float)texture.width * transform.localScale / 2.f, (float)texture.height * transform.localScale / 2.f };
}
