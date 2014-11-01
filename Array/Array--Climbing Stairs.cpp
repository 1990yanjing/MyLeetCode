#include "Solution.h"
using namespace std;

/**
 * Array
 * No.70 Climbing Stairs
 * 斐波那契数列,需用迭代法求解第n项，否则会超时
 * f(n) = f(n - 1) + f(n - 2)
 */
int climbStairs(int n)
{
	int pre = 2;
	int bpre = 1;
	int ret = 0;

	if(n == 1)
		return 1;
	if(n == 2)
		return 2;

	for(int i = 3; i <= n; ++i)
	{
		ret = pre + bpre;
		bpre = pre;
		pre = ret;
	}

	return ret;
}
