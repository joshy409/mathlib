#pragma once
#include "math.h"
//returns smaller of the two
template<typename T>
T min(T a, T b)
{
	return a < b ? a : b;
}

//returns smaller of the two
template<typename T, typename... Args>
T min(T a, T b, Args... args) {
	return (a < b ? min (a,args...) : min(b,args...));
}

//returns larger of the two
template<typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

//returns larger of the two
template<typename T, typename... Args>
T max(T a, T b, Args... args) {
	return (a > b ? max(a, args...) : max(b, args...));
}

//returns value no smaller than min and no larger than max
template<typename T>
T clamp(T value, int min, int max) {
	value < min ? min : value;
	value > max ? max : value;
	return value;
}

//Defined as PI 
constexpr double PI = 3.141592653589793238;
//Multiply this with a angle measure expressed in degrees to get its equivalent in radians.
constexpr double DEG_TO_RAD = PI/180;
//Multiply this with a angle measure expressed in radians to get its equivalent in degrees.
constexpr double RAD_TO_DEG = 180/PI;

//returns the absolute value of val
template<typename T>
T abs(T val) {
	return val < 0 ? val * -1 : val;
}

//return base to the power of exp base^power
template<typename T>
T pow(T base, int power) {
	T temp = base;
	for (int i = 1; i < power; i++) {
		base *= temp;
	}
	return base;
}

//returns true if teh value is a power of two, otherwise returns false
bool isPowerOfTwo(int val);

//returns the next power of two after the given value
//the behavior of this function if teh next power of two is beyond the range of int is not defined
int nextPowerOfTwo(int val);

//moves the current value towards the target value. The maximum change should not exceed maxDelta
//the value returned should never move past the target value
template<typename T>
T moveTowards(T current, T target, T maxDelta) {
	if (current > target) {
		current += maxDelta;
		current = clamp(current, , target);
		return current;
	}
	else if (current < target) {
		current -= maxDelta;
		current = clamp(target, , current);
		return current;
	}
	else {
		return current;
	}
}

