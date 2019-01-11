#pragma once
#include "vec2.h"
#include "vec3.h"
#include "mat3.h"

struct transform2d
{
	transform2d();

	vec2 localPos;
	float localRot;
	float localScale;

	void translate(const vec2 &offset);
	void rotate(const float angle);
	void scale(const float scale);

	//void lookAt(const transform2d &target);
	//vec2 forward() const;
	//void setForward(const vec2 &newFwd);
	
	mat3 getTRSMatrix() const;
	mat3 getTSMatrix() const;
};