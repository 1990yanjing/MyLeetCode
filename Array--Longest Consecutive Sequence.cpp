#include "Solution.h"
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

/**
 * Array
 * No.128 Longest Consecutive Sequence
 * O(nlogn) 
 * 先排序（O(nlogn)），后找出最长连续序列
 */
int longestConsecutive(vector<int> &num) 
{
	sort(num.begin(), num.end());
	int maxlen = 1, len = 1;
	for(int i = 0; i < num.size(); i++)
	{
		if(i + 1 < num.size())
		{
			if(num[i] == num[i + 1] - 1)
				len++;
			else
			{
				if(num[i] == num[i + 1])
					continue;
				else
				{
					if(len >= maxlen)
						maxlen = len;
					len = 1;
				}
			}
		}
	}
	return max(maxlen, len);
}

/********************更优解********************/
/**
 * O(n)
 * 由于序列里的元素是无序的，又要求O(n)，首先要想到用哈希表。
 * 用一个哈希表map<int, bool> used 记录每个元素是否使用，
 * 对每个元素，以该元素为中心，往左右扩张，直到不连续为止，记录下最长的长度
 */
int longestConsecutive(vector<int> &num) 
{
	map<int, bool> used_map;

	for(int i = 0; i < num.size(); i++) 
		used_map[num[i]] = false;
	int longest = 0;
	for(int i = 0; i < num.size(); i++)
	{
		if(used_map[num[i]]) 
			continue;
		int length = 1;

		used_map[num[i]] = true;
		for(int j = num[i] + 1; used_map.find(j) != used_map.end(); ++j)
		{
			used_map[j] = true;
			length++;
		}
		for(int j = num[i] - 1; used_map.find(j) != used_map.end(); --j)
		{
			used_map[j] = true;
			length++;
		}
		longest = max(longest, length);
	}
	return longest;
}