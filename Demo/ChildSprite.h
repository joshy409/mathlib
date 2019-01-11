#pragma once
#include "Sprite.h"
#include <vector>
#include <iostream>
class ChildSprite :
	public Sprite
{
public:
	Sprite*  parent;

	ChildSprite(Sprite* _parent);
	ChildSprite(Sprite* _parent, std::string texturePath);

	void update();
};

