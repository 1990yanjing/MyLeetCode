#include "Solution.h"

/**
 * String
 * No.65 Valid Number
 * 即实现一个标准库函数中strtod()函数，即将字符串转换为Double
 * strtod()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，
 * 到出现非数字或字符串结束时('\0')才结束转换，并将结果返回。若endptr不为NULL，
 * 则会将遇到不合条件而终止的nptr中的字符指针由endptr传回。
 * 参数nptr字符串可包含正负号、小数点或E(e)来表示指数部分。如123.456或123e-2。
 */
/**　有限自动机解法
 * 将可能输入映射为枚举值
 * 建立状态转移矩阵
 */

bool isNumber(string s) 
{
	enum InputType {
		INVALID, // 0
		SPACE, // 1
		SIGN, // 2
		DIGIT, // 3
		DOT, // 4
		EXPONENT, // 5
		NUM_INPUTS // 6
	};
	const int transitionTable[][NUM_INPUTS] = {
		-1, 0, 3, 1, 2, -1, // next states for state 0
		-1, 8, -1, 1, 4, 5, // next states for state 1
		-1, -1, -1, 4, -1, -1, // next states for state 2
		-1, -1, -1, 1, 2, -1, // next states for state 3
		-1, 8, -1, 4, -1, 5, // next states for state 4
		-1, -1, 6, 7, -1, -1, // next states for state 5
		-1, -1, -1, 7, -1, -1, // next states for state 6
		-1, 8, -1, 7, -1, -1, // next states for state 7
		-1, 8, -1, -1, -1, -1, // next states for state 8
	};
	int state = 0;
	for (int i = 0; i < s.size(); ++i) {
		InputType inputType = INVALID;
		if (isspace(s[i]))
			inputType = SPACE;
		else if (s[i] == '+' || s[i] == '-')
			inputType = SIGN;
		else if (isdigit(s[i]))
			inputType = DIGIT;
		else if (s[i] == '.')
			inputType = DOT;
		else if (s[i] == 'e' || s[i] == 'E')
			inputType = EXPONENT;
		// Get next state from current state and input symbol
		state = transitionTable[state][inputType];
		// Invalid input
		if (state == -1) return false;
	}
	// If the current state belongs to one of the accepting (final) states,
	// then the number is valid
	return state == 1 || state == 4 || state == 7 || state == 8;
}
/**
 * 偷懒版
 * 利用标准库函数strtod()
 */
bool isNumber (string s) 
{
	char* endptr;
	strtod (s.c_str(), &endptr);
	if (endptr == s.c_str()) return false;
	for (; *endptr; ++endptr)
		if (!isspace (*endptr)) return false;
	return true;
}