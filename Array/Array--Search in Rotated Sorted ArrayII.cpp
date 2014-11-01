#include "Solution.h"

/**
 * Array
 * No.81 Search in Rotated Sorted ArrayII
 * 特点：有序旋转序列中有重复元素，在二分查找中，确定边界是跳过重复的元素
 * 如果A[m]>=A[l] 不能确定递增，那就把它拆分成两个条件：
 *  若A[m]>A[l]，则区间[l,m] 一定递增
 *	若A[m]==A[l] 确定不了，那就l++，往下看一步即可。
 */
bool searchII(int A[], int n, int target) 
{
	int low = 0;
	int high = n;
	while(low < high)
	{
		const int mid = (low + high) / 2;
		if(target == A[mid])
			return true;
		if(A[low] < A[mid])
		{
			if(target >= A[low] && target < A[mid])
				high = mid;
			else
				low = mid + 1;
		}
		else
		{
			if(A[low] > A[mid])
			{
				if(target <= A[high - 1] && target > A[mid])
					low = mid + 1;
				else
					high = mid;
			}
			else
				low++;
		}
	}
	return false;
}