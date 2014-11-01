#include "Solution.h"

/**
 * String
 * No.44 Wildcard Matching
 * 实现简单的通配符规则匹配，正则规则如下：
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 算法巧妙，简单，但是难以总结复用
 */
 /**
  * 递归会超时，便于理解
  */
bool isMatch(const char *s, const char *p) 
{
	if (*p == '*') 
	{
		while (*p == '*') ++p; //skip continuous '*'
		if (*p == '\0') return true;
		while (*s != '\0' && !isMatch(s, p)) ++s;
		return *s != '\0';
	}
	else if (*p == '\0' || *s == '\0') return *p == *s;
	else if (*p == *s || *p == '?') return isMatch(++s, ++p);
	else return false;
}

/**
 * 迭代做法
 */

bool isMatch(const char *s, const char *p) 
{
	bool star = false;
	const char *str, *ptr;
	for (str = s, ptr = p; *str != '\0'; str++, ptr++) 
	{
		switch (*ptr) 
		{
			case '?':
				break;
			case '*':
				star = true;
				s = str, p = ptr;//标记p为星号的位置和此时s的位置，并跳过所有的*，将s从此位置依次扫描
				while (*p == '*') p++; //skip 跳过连续的 '*',并保存了*之后的位置
				if (*p == '\0') return true;
				str = s - 1;
				ptr = p - 1;
				break;
			default:
				if (*str != *ptr) { //例如正则为 ‘*abc’ 字符串为 ‘zzzzabc’
					                // 如果前面没有'*'，则匹配不成功
					if (!star) return false;
					s++;
					str = s - 1;//str 位置向后移继续匹配
					ptr = p - 1;//正则串移到*之后的开始位置
				}
		}
	}
	while (*ptr == '*') 
		ptr++;
	return (*ptr == '\0');//最后剩余正则规则不为空，则失败
}
