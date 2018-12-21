#include "mat3.h"

mat3::mat3()
{
	xAxis = { 0,0,0 };
	yAxis = { 0,0,0 };
	zAxis = { 0,0,0 };
}

mat3::mat3(float * ptr)
{
	std::copy(ptr, ptr + 9, m);
	xAxis = { m[0],m[1],m[2] };
	yAxis = { m[3],m[4],m[5] };
	zAxis = { m[6],m[7],m[8] };
}

mat3::mat3(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	xAxis = { _m1,_m2,_m3 };
	yAxis = { _m4,_m5,_m6 };
	zAxis = { _m7,_m8,_m9 };
}

mat3::operator float*()
{	
	return m;
}

vec3 & mat3::operator[](const int index)
{
	return axis[index];
}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 temp;
	temp.xAxis = vec3{m1*rhs.m1 + m2 * rhs.m4 + m3 * rhs.m7,
					  m1*rhs.m2 + m2 * rhs.m5 + m3 * rhs.m8,
					  m1*rhs.m3 + m2 * rhs.m6 + m3 * rhs.m9, };

	temp.yAxis = vec3{m4*rhs.m1 + m5 * rhs.m4 + m6 * rhs.m7,
					  m4*rhs.m2 + m5 * rhs.m5 + m6 * rhs.m8,
					  m4*rhs.m3 + m5 * rhs.m6 + m6 * rhs.m9, };

	temp.zAxis = vec3{ m7*rhs.m1 + m8 * rhs.m4 + m9 * rhs.m7,
					   m7*rhs.m2 + m8 * rhs.m5 + m9 * rhs.m8,
					   m7*rhs.m3 + m8 * rhs.m6 + m9 * rhs.m9, };

	return temp;
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	xAxis = vec3{ m1*rhs.m1 + m2 * rhs.m4 + m3 * rhs.m7,
		m1*rhs.m2 + m2 * rhs.m5 + m3 * rhs.m8,
		m1*rhs.m3 + m2 * rhs.m6 + m3 * rhs.m9, };

	yAxis = vec3{ m4*rhs.m1 + m5 * rhs.m4 + m6 * rhs.m7,
		m4*rhs.m2 + m5 * rhs.m5 + m6 * rhs.m8,
		m4*rhs.m3 + m5 * rhs.m6 + m6 * rhs.m9, };

	zAxis = vec3{ m7*rhs.m1 + m8 * rhs.m4 + m9 * rhs.m7,
		m7*rhs.m2 + m8 * rhs.m5 + m9 * rhs.m8,
		m7*rhs.m3 + m8 * rhs.m6 + m9 * rhs.m9, };

	return *this;
}

bool mat3::operator==(const mat3 & rhs) const
{
	bool result = true;
	for (int i = 0; i < 9; i++) {
		if (m[i] != rhs.m[i]) {
			result = false;
		}
	}
	return result;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	bool result = true;
	for (int i = 0; i < 9; i++) {
		if (m[i] == rhs.m[i]) {
			result = false;
		}
	}
	return result;
}

mat3 mat3::identity()
{
	return mat3(1,0,0,0,1,0,0,0,1);
}

void mat3::set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	xAxis = vec3{ m1,m2,m3 };
	yAxis = vec3{ m4,m5,m6 };
	zAxis = vec3{ m7,m8,m9 };
}

void mat3::set(float * ptr)
{
	std::copy(ptr, ptr + 9, m);
	xAxis = { m[0],m[1],m[2] };
	yAxis = { m[3],m[4],m[5] };
	zAxis = { m[6],m[7],m[8] };
}

void mat3::transpose()
{
	float temp[9];
	std::copy(m, m + 9, temp);
	xAxis = { temp[0],temp[3],temp[6] };
	yAxis = { temp[1],temp[4],temp[7] };
	zAxis = { temp[2],temp[5],temp[8] };
}

mat3 mat3::getTranspose()
{
	mat3 temp;
	temp.xAxis = { m[0],m[3],m[6] };
	temp.yAxis = { m[1],m[4],m[7] };
	temp.zAxis = { m[2],m[5],m[8] };
	return temp;
}

mat3 mat3::getInverse() const
{
	return mat3();
}

//2d
mat3 mat3::translation(float x, float y)
{
	return mat3(1,0,x,0,1,y,0,0,1);
}

mat3 mat3::translation(const vec2 & vec)
{
	return mat3(1, 0, vec.x, 0, 1, vec.y, 0, 0, 1);
}

mat3 mat3::rotation(float rot) //rot in radians
{
	return mat3(cos(rot),-sin(rot),0,sin(rot),cos(rot),0,0,0,1);
}

mat3 mat3::scale(float xScale, float yScale)
{
	return mat3(xScale,0,0,0,yScale,0,0,0,1);
}

vec3 mat3::operator*(const vec3 & rhs) const
{
	vec3 temp = { m[0] * rhs.x + m[3] * rhs.y + m[6] * rhs.z,m[1] * rhs.x + m[4] * rhs.y + m[7] * rhs.z,m[2] * rhs.x + m[5] * rhs.y + m[8] * rhs.z };
	return temp;
}

vec2 mat3::operator*(const vec2 & rhs) const
{
	vec2 temp = { m[0] * rhs.x + m[2] * rhs.y, m[1] * rhs.x + m[3] * rhs.y};
	return temp;
}
