#include "Solution.h"

/**
 * Array
 * No.80 Remove Duplicates from Sorted Array II
 * 思路与I相同
 * date:2014.12.31
 */
int removeDuplicatesII(int A[], int n)
{
	if(n == 0)
		return 0;
	int times = 1;
	int index = 1;
	for(int i = 0; i < n; i++)
	{
		if(i+1 < n)
		{
			if(A[i] != A[i+1])
			{
				A[index++] = A[i+1];
				times = 1;
			}
			else
			{
				if(times < 2)
					A[index++] = A[i+1];
				times++;
			}
		}
	}
	return index;
}
