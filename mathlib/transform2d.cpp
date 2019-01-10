#include "transform2d.h"


transform2d::transform2d()
{
	localPos = { 0,0 };
	localRot = 0.f;
	localScale = 1.f;
}

void transform2d::translate(const vec2 & offset)
{
	localPos += offset;
}

void transform2d::rotate(const float angle)
{
	localRot = angle;
}

void transform2d::scale(const float scale)
{
	localScale = scale;
}

mat3 transform2d::getTRSMatrix() const
{
	mat3 trxMatrix = { 1,0,0,0,1,0,0,0,1 };
	return trxMatrix;
}

