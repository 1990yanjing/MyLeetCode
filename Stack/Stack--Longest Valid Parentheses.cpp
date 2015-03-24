#include "Solution.h"

/**
 * Stack
 * No.32 Longest Valid Parentheses
 * 只要求括号完整与之前题目不同，之前题目要求一次匹配 (){}[] 才合法， ({}) 不合法
 */

/**
 * 一维逆向动态规划
 * http://blog.csdn.net/cfc1243570631/article/details/9304525
 */
int longestValidParentheses(string s) 
{
	const int n = s.size();
	int *dq;
	dq = new int[n];

	fill_n(dq, n, 0);

	int ret = 0;

	for(int i = s.size() - 2; i >= 0; --i)
	{
		int match = i + dq[i + 1] + 1;
		if(s[i] == '(' && match < s.size() && s[match] == ')')
		{
			dq[i] = dq[i + 1] + 2;
			if(match + 1 < s.size())
				dq[i] += dq[match + 1];
		}
		ret = max(ret, dq[i]);
	}
	
	delete[] dq;

	return ret;
}