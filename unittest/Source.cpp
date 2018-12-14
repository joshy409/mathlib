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

	//assert(min(2, 3, 4) == 2); // the min value of 2, 3, 4 is 2
	//assert(max(2, 3) == 3); // the max value of 2, 3 is 3
	//assert(max(2, 3, 4) == 4); // the max value of 2, 3, 4 is 4
	//assert(abs(-5) == 5);       // the abs value of -5 is 5
	//assert(clamp(3, 1, 6) == 3); // 3 clamped between 1 ~ 6 is 3
	//assert(clamp(0, 1, 6) == 1); // 0 clamped between 1 ~ 6 is 1
	//assert(clamp(9, 1, 6) == 6); // 6 clamped between 1 ~ 6 is 6
	//assert(pow(2, 4) == 16);      // 2 to the power of 4 is 16
	//assert(isPowerOfTwo(124) == false); // 124 is not a power of 2
	//assert(isPowerOfTwo(128) == true); // 128 is a power of 2
	//assert(nextPowerOfTwo(63) == 64); // next power of two after 63 is 64
	//assert(nextPowerOfTwo(64) == 128); // next power of two after 64 is 128
	//assert(moveTowards(6, 0, 1) == 5); // 6 moving toward 0 with delta being 1 = 5
	//assert(moveTowards(0, 3, 1) == 1); // 0 moving toward 3 with delta being 1 = 1

	seedRand(675248);
	int a = 675248;
	a = pow(a, 2);
	std::cout << a << std::endl;

	std::cout << rand(4000, 4000) << std::endl;
	
	a = 332812;
	a = pow(a, 2);
	std::cout << a << std::endl;
	std::cout << rand(1, 999999) << std::endl;
	return 0;
}