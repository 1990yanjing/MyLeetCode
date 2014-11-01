#include "Solution.h"

/**
 * String
 * No.8 Add Binary
 * 求两个二进制字符串的和
 * string和vector的api很像，比如都可以在任意位置插入元素，insert
 */
string addBinary(string a, string b) 
{
	int carray = 0;
	int sum = 0;
	int digit = 0;
	string ret = "";
	int i = a.size() - 1;
	int j = b.size() - 1;
	while(i >= 0 && j >= 0)
	{
		sum = a[i] - '0' + b[j] - '0' + carray;
		digit = sum % 2;
		carray = sum / 2;
		ret.insert(ret.begin(), digit + '0');
		i--;
		j--;
	}
	if(i >= 0)
	{
		while(i >= 0)
		{
			sum = a[i] - '0' + carray;
	 		digit = sum % 2;
	 		carray = sum / 2;
	 		ret.insert(ret.begin(), digit + '0');
	 		i--;
		}
	}

	if(j >= 0)
	{
		while(j >= 0)
		{
			sum = b[j] - '0' + carray;
	 		digit = sum % 2;
	 		carray = sum / 2;
	 		ret.insert(ret.begin(), digit + '0');
	 		j--;
		}
	}

	if(carray != 0)
		ret.insert(ret.begin(), carray + '0');

	return ret;
}