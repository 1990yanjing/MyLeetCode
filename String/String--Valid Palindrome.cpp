#include "Solution.h"

/**
 * String
 * No.125 Valid Palindrome
 * 判断字符串是否是回文的
 * string 底层基本结构就是char数组,所以string的每个元素就是char类型
 * 判断是否为字母isalpha(char)
 * 判断是否为数字isdigit(char)
 * 转换为小写tolower(char)
 * stl Api reverse(iterator begin, iterator end) 倒置string、vector。。。
 */
bool isPalindrome(string s)
{
	if(s.empty())
 		return true;
	string::iterator iter = s.begin();
	while(iter != s.end())
	{
		if(!isalpha(*iter) && !isdigit(*iter))
		{
			iter = s.erase(iter);
			if(iter == s.begin())
				continue;
			else
				iter--;
		}
		else
		{
			*iter = tolower(*iter);
		}
		iter++;
	}
	string tmp = s;
	reverse(tmp.begin(), tmp.end());
	return s == tmp;
}