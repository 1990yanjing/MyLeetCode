#include "Solution.h"

/**
 * Stack
 * No.20 Valid Parentheses
 * 判断括号表达式是否完整
 *　要求一次匹配 (){}[] 才合法， ({}) 不合法
 */
bool isValid(string s) 
{
	stack<char> istac;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '(' || s[i] == '[' || s[i] == '{')
			istac.push(s[i]);
		else
		{
			if(istac.empty())
				return false;
			char tmp = istac.top();
			if(s[i] == ')')
			{
				if(tmp == '(')
					istac.pop();
				else
					return false;
			}

			if(s[i] == ']')
			{
				if(tmp == '[')
					istac.pop();
				else
					return false;
			}

			if(s[i] == '}')
			{
				if(tmp == '{')
					istac.pop();
				else
					return false;
			}
		}
	}

	return istac.empty();
}