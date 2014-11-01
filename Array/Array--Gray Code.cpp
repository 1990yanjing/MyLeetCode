#include "Solution.h"
#include <math.h>
using namespace std;

/**
 * Array
 * No.89 Gray Code
 * 自然码装格雷码
 * 格雷码有数学公式，整数n的格雷码是n异或(n/2)
 */
vector<int> grayCode(int n) 
{
	vector<int> ret;
	int size = pow(2.0, n);
	for(int i = 0; i < size; ++i)
		ret.push_back(getGray(i));
	return ret;
}
int getGray(unsigned int n)
{
	return n ^ (n / 2);
}

