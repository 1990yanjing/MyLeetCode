#include "Solution.h"

/**
 * String
 * No.10 Regular Expression Matching
 * 实现简单的正则表达式的规则匹配，正则规则如下：
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 递归，主要是注意对于*和.*的处理
 * 算法巧妙，简单，但是难以总结复用
 */
bool isMatch(const char *s, const char *p) 
{
	if(*p == '\0')
		return *s == '\0';

	if(*(p + 1) != '*')//下一个元素不是*
	{
		if(*p == *s || (*p == '.' && *s != '\0'))
			return isMatch(s + 1, p + 1);
		else
			return false;
	}
	else//下一个元素是*
	{
		while(*p == *s || (*p == '.' && *s != '\0'))
		{
			if(isMatch(s, p + 2))
				return true;
			s++;
		}
		return isMatch(s, p + 2);
	}
}