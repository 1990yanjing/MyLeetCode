#include "Solution.h"

/**
 * Array
 * Remove Duplicates from Sorted Array
 * 注意判断边界条件
 */
int removeDuplicates(int A[], int n)
{
	if(n == 0)
		return n;
	int index = 1;
	for(int i = 0; i < n; i++)
	{
		if(i + 1 < n && A[i] != A[i + 1])
		{
			A[index] = A[i + 1];
			index++;
		}
	}
	return index;
}
