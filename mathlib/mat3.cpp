#include "mat3.h"

mat3::mat3()
{
	xAxis = { 0,0,0 };
	yAxis = { 0,0,0 };
	zAxis = { 0,0,0 };
	axis[0] = xAxis;
	axis[1] = yAxis;
	axis[2] = zAxis;
	m1, m2, m3, m4, m5, m6, m7, m8, m9 = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mm[i][j] = 0;
			m[i*3 + j] = 0;
		}
	}
}

mat3::mat3(float * ptr)
{
	std::copy(ptr, ptr + 9, m);
	xAxis = { m[0],m[1],m[2] };
	yAxis = { m[3],m[4],m[5] };
	zAxis = { m[6],m[7],m[8] };
	axis[0] = xAxis;
	axis[1] = yAxis;
	axis[2] = zAxis;
	m1 = m[0]; m2 = m[1]; m3 = m[2]; m4 = m[3]; m5 = m[4]; m6 = m[5]; m7 = m[6]; m8 = m[7]; m9 = m[8];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mm[i][j] = m[i*3+j];
		}
	}
}

mat3::mat3(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	xAxis = { _m1,_m2,_m3 };
	yAxis = { _m4,_m5,_m6 };
	zAxis = { _m7,_m8,_m9 };
	axis[0] = xAxis;
	axis[1] = yAxis;
	axis[2] = zAxis;
	m1 = _m1; m2 = _m2; m3 = _m3; m4 = _m4; m5 = _m5; m6 = _m6; m7 = _m7; m8 = _m8; m9 = _m9;
	for (int i = 0; i < 3; i++) {
		mm[i][0] = axis[i].x;
		mm[i][1] = axis[i].y;
		mm[i][2] = axis[i].z;
		for (int j = 0; j < 3; j++) {
			m[i * 3 + j] = mm[i][j];
		}
	}
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
	return mat3();
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	// TODO: insert return statement here
}

bool mat3::operator==(const mat3 & rhs) const
{
	return false;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	return false;
}

void mat3::populate(const vec3 * rhs)
{
	for (int i = 0; i < 3; i++) {
		mm[i][0] = rhs[i].x;
		mm[i][1] = rhs[i].y;
		mm[i][2] = rhs[i].z;
		for (int j = 0; j < 3; j++) {
			m[i * 3 + j] = mm[i][j];
		}
	}
	m1 = m[0]; m2 = m[1]; m3 = m[2]; m4 = m[3]; m5 = m[4]; m6 = m[5]; m7 = m[6]; m8 = m[7]; m9 = m[8];
}
