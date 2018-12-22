#include "transform2d.h"

vec2 transform2d::localPosition() const
{
	return vec2(trsMatrix.z1,trsMatrix.z2);
}

//?
float transform2d::localRotation() const
{
	return 0.0f;
}

//?
vec2 transform2d::localScale() const
{
	return vec2();
}

void transform2d::setLocalPosition(const vec2 & newPos)
{
	trsMatrix.axis[2] = { newPos.x, newPos.y, 1 };
}

void transform2d::setLocalRotation(const float newRot)
{	
	/*trsMatrix.x1 *= cos(newRot);
	trsMatrix.x2 *= sin(newRot);
	trsMatrix.y1 *= -sin(newRot);
	trsMatrix.y2 *= cos(newRot);*/

	trsMatrix *= mat3::rotation(newRot);
}

void transform2d::setLocalScale(const vec2 & newScale)
{
	trsMatrix.x1 *= newScale.x;
	trsMatrix.y2 *= newScale.y;
}

void transform2d::translate(const vec2 & offset)
{
	trsMatrix *= mat3::translation(offset);
}

void transform2d::rotate(const float angle)
{
	trsMatrix *= mat3::rotation(angle);
}

void transform2d::scale(const vec2 & scale)
{
	trsMatrix *= mat3::scale(scale);
}
