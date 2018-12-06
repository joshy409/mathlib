#include <iostream>
#include <cassert>
#include "utils.h"
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
	assert(nextPowerOfTwo(64) == 128); //next power of two after 64 is 128

	return 0;
}