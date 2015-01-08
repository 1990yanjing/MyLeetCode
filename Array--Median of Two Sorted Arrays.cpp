#include "Solution.h"

/**
 * Array
 * No.4 Median of Two Sorted Arrays
 * I call it 对位法 O(m+n)
 */
double findMedianSortedArrays(int A[], int m, int B[], int n)
{	
	int indexA = 0;
	int indexB = 0;
	int index = 0;
	double mid = 0;
	double mid1 = 0, mid2 = 0;
	if((m + n) % 2 != 0)
	{
		while(index != (m + n + 1) / 2)
		{
			if(indexA < m && indexB < n)
			{
				if(A[indexA] < B[indexB])
					mid = A[indexA++];
				else
					mid = B[indexB++];
			}
			else
			{
				if(indexA >= m)
					mid = B[indexB++];
				else
					mid = A[indexA++];
			}
			index++;
		}
	}
	else
	{
		while(index != (m + n + 1) / 2 + 1)
		{
			if(indexA < m && indexB < n)
			{
				if(A[indexA] < B[indexB])
					mid = A[indexA++];
				else
					mid = B[indexB++];
			}
			else
			{
				if(indexA >= m)
					mid = B[indexB++];
				else
					mid = A[indexA++];
			}
			index++;
			if(index == (m + n + 1) / 2)
				mid1 = mid;
			if(index == (m + n + 1) / 2 + 1)
				mid2 = mid;
		}
		mid = (mid1 + mid2) / 2;
	}
	return mid;
}