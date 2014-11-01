#include "Solution.h"

/**
 * String
 * No.5 Longest Palindromic Substring
 * 找到字符串s中的最长回文子串
 * 动态规划
 * 状态转移方程，f[i][j] 代表s字符串中从位置i到j的字符串是否是回文的：
 *          [ true                            j = i
 * f[i][j] <  s[i] = s[j]                     j = i + 1
 *          [ s[i] = s[i] && f[i + 1][j - 1]  j > i + 1
 */
string longestPalindrome(string s)
{
	const int n = s.size();
	bool f[n][n];
	fill_n(&f, n*n, false);
	int max_len = 1, start = 0;

	for(int i = 0; i < n; ++i)
	{
		f[i][i] = true;
		for(int j = 0; j < i; ++j)
		{
			f[j][i] = (s[i] == s[j] && (i - j < 2 || s[j + 1][i - 1]));
			if(f[j][i] && max_len < (i - j + 1))
			{
				max_len = i - j + 1;
				start = j;
			}
		}
	}
	return s.substr(start, max_len);
}