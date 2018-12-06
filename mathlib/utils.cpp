#include "utils.h"

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
