#include "Solution.h"

/**
 * String
 * No.14 Longest Common Prefix 
 * 求一组字符串的最长公用前缀
 * 将这组字符串看做二维数组，按照列-行遍历，判断每一列是否相同，相同则追加到结果字符串后
 * 注意：
 *    边界条件，即空和只有一个字符串（结果就是这个字符串）的情况
 */
string longestCommonPrefix(vector<string> &strs) 
{
	string ret = "";

	if(strs.empty())
		return ret;

	if(strs.size() == 1)
		return strs[0];

	for(int j = 0 ; j < INT_MAX; ++j)
	{
		for(int i = 0;i < strs.size() - 1; ++i)
		{
			if(j < strs[i].size() && j < strs[i + 1].size())
			{
				if(strs[i][j] != strs[i + 1][j])
					return ret;
			}
			else
				return ret;
		}
		ret += strs[0][j];
	}
	return ret;
}