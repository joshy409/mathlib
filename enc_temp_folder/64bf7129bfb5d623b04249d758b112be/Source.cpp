#include <iostream>
#include <cassert>
#include "utils.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
typedef vec2 Vector2;
typedef vec3 Vector3;
typedef vec4 Vector4;

int main() {

	assert(min(2, 3, 4) == 2); // the min value of 2, 3, 4 is 2
	assert(max(2, 3) == 3); // the max value of 2, 3 is 3
	assert(max(2, 3, 4) == 4); // the max value of 2, 3, 4 is 4
	assert(abs(-5) == 5);       // the abs value of -5 is 5
	assert(clamp(3, 1, 6) == 3); // 3 clamped between 1 ~ 6 is 3
	assert(clamp(0, 1, 6) == 0); // 0 clamped between 1 ~ 6 is 0
	assert(clamp(9, 1, 6) == 9); // 6 clamped between 1 ~ 6 is 9
	assert(pow(2, 4) == 16);      // 2 to the power of 4 is 16
	assert(isPowerOfTwo(124) == false); // 124 is not a power of 2
	assert(isPowerOfTwo(128) == true); // 128 is a power of 2
	assert(nextPowerOfTwo(63) == 64); // next power of two after 63 is 64
	assert(nextPowerOfTwo(64) == 128); // next power of two after 64 is 128
	assert(moveTowards(6, 0, 1) == 5); // 6 moving toward 0 with delta being 1 = 5
	assert(moveTowards(0, 3, 1) == 1); // 0 moving toward 3 with delta being 1 = 1
	Vector2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	Vector3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	Vector4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	v2a = Vector2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	return 0;
}