#include "utils.h"

int pow(int base, int power)
{
	int temp = base;
	for (int i = 1; i < power; i++) {
		base *= temp;
	}
	return base;
}

bool isPowerOfTwo(int val)
{
	double temp = log2(val);
	return temp == static_cast<int> (temp) ? true : false;
}


int nextPowerOfTwo(int val)
{
	double temp = log2(val);
	return pow(2,static_cast<int> (temp) + 1);
}

//TODO: ??
float moveTowards(float current, float target, float maxDelta)
{

	return 0.0f;
}
