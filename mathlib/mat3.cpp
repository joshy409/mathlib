#include "mat3.h"

mat3::mat3()
{
	xAxis = { 0,0,0 };
	yAxis = { 0,0,0 };
	zAxis = { 0,0,0 };
	populate();
}

mat3::mat3(float * ptr)
{
	std::copy(ptr, ptr + 9, m);
	xAxis = { m[0],m[1],m[2] };
	yAxis = { m[3],m[4],m[5] };
	zAxis = { m[6],m[7],m[8] };
	populate();
}

mat3::mat3(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	xAxis = { _m1,_m2,_m3 };
	yAxis = { _m4,_m5,_m6 };
	zAxis = { _m7,_m8,_m9 };
	populate();
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

	temp.populate();
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

	populate();
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
	populate();
}

void mat3::set(float * ptr)
{
	std::copy(ptr, ptr + 9, m);
	xAxis = { m[0],m[1],m[2] };
	yAxis = { m[3],m[4],m[5] };
	zAxis = { m[6],m[7],m[8] };
	populate();
}

void mat3::transpose()
{
	xAxis = { m[0],m[3],m[6] };
	yAxis = { m[1],m[4],m[7] };
	zAxis = { m[2],m[5],m[8] };
	populate();
}

mat3 mat3::getTranspose()
{
	mat3 temp;
	temp.xAxis = { m[0],m[3],m[6] };
	temp.yAxis = { m[1],m[4],m[7] };
	temp.zAxis = { m[2],m[5],m[8] };
	temp.populate();
	return temp;
}

mat3 mat3::getInverse() const
{
	return mat3();
}

void mat3::populate()
{
	axis[0] = xAxis;
	axis[1] = yAxis;
	axis[2] = zAxis;
	for (int i = 0; i < 3; i++) {
		mm[i][0] = axis[i].x;
		mm[i][1] = axis[i].y;
		mm[i][2] = axis[i].z;
		for (int j = 0; j < 3; j++) {
			m[i * 3 + j] = mm[i][j];
		}
	}
	m1 = m[0]; m2 = m[1]; m3 = m[2]; m4 = m[3]; m5 = m[4]; m6 = m[5]; m7 = m[6]; m8 = m[7]; m9 = m[8];
}
