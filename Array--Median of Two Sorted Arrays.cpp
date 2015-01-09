#include "Solution.h"

/**
 * Array
 * No.4 Median of Two Sorted Arrays
 * I call it 对位法（归并） O(m+n)
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

/***********************更优解*******************/
/**
 * O(logn)
 * 题目转变为在两个有序序列中第K大的元素
 * 比较A[k/2 - 1] 和 B[k/2 - 1] 的大小，递归每次减少k/2个元素
 */
double findMedianSortedArrays(int A[], int m, int B[], int n) 
{
	int total = m + n;
	if (total & 0x1)
		return find_kth(A, m, B, n, total / 2 + 1);
	else
		return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
}

static int find_kth(int A[], int m, int B[], int n, int k) 
{
	//always assume that m is equal or smaller than n
	if (m > n) return find_kth(B, n, A, m, k);
	if (m == 0) return B[k - 1];
	if (k == 1) return min(A[0], B[0]);
	
	//divide k into two parts
	int ia = min(k / 2, m), ib = k - ia;
	if (A[ia - 1] < B[ib - 1])
		return find_kth(A + ia, m - ia, B, n, k - ia);
	else if (A[ia - 1] > B[ib - 1])
		return find_kth(A, m, B + ib, n - ib, k - ib);
	else
		return A[ia - 1];
}