#pragma once
#include "vec2.h"
#include "vec3.h"
#include "mat3.h"

struct transform2d
{
	vec2 localPosition() const;
	float localRotation() const;
	vec2 localScale() const;

	void setLocalPosition(const vec2 &newPos);
	void setLocalRotation(const float newRot);
	void setLocalScale(const vec2 &newScale);

	void translate(const vec2& offset);
	void rotate(const float angle);
	void scale(const vec2 & scale);

private:
	mat3 trsMatrix = { 1,0,0,0,1,0,0,0,1 };
};