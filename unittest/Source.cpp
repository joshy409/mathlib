#include <iostream>
#include <cassert>
#include "utils.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat3.h"

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


	mat3 a;
	for (int i = 0; i < 9; i++) {
		std::cout << a.m[i] << " ";
	}
	std::cout << std::endl;

	mat3 b = { 9,8,7,6,5,4,3,2,1 };
	for (int i = 0; i < 9; i++) {
		std::cout << b.m[i] << " ";
	}
	std::cout << std::endl;


	float z[9] = { 1,2,3,4,5,6,7,8,9 };
	mat3 c = z;
	for (int i = 0; i < 9; i++) {
		std::cout << c.m[i] << " ";
	}
	std::cout << std::endl;

	float* ee = a;

	for (int i = 0; i < 9; i++) {
		std::cout << ee[i] << " ";
	}
	std::cout << std::endl;
	vec3 d = c[0];

	std::cout << d.x << " " << d.y << " " << d.z;
	std::cout << std::endl;
	vec3 f = c[1];
	std::cout << f.x << " " << f.y << " " << f.z;
	std::cout << std::endl;
	vec3 g = c[2];
	std::cout << g.x << " " << g.y << " " << g.z;
	std::cout << std::endl;


	a == mat3(0,0,0,0,0,0,0,0,0) ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;
	a != b ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;
	mat3 test = mat3::identity();
	for (int i = 0; i < 9; i++) {
		std::cout << test.m[i] << " ";
	}
	std::cout << std::endl;
	
	a.set(1, 2, 3, 4, 5, 6, 7, 8, 9);
	//a.transpose();
	for (int i = 0; i < 3; i++) {
		std::cout << a.m[i] << " " << a.m[i+3] << " " << a.m[i+6] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < 3; i++) {
		std::cout << b.m[i] << " " << b.m[i + 3] << " " << b.m[i + 6] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	a *= b;

	for (int i = 0; i < 3; i++) {
		std::cout << a.m[i] << " " << a.m[i + 3] << " " << a.m[i + 6] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}