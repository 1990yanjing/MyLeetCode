#include "Solution.h"

/**
 * Array
 * No.33 Search in Rotated Sorted Array
 * 查找，二分查找O(logn)
 * 难点在于确定左右边界
 * date:2014.12.31
 */
int search(int A[], int n, int target)
{
    int low = 0;
    int high = n;
    while(low < high)
    {
    	const int mid = (low + high) / 2;
    	if(A[mid] == target)
    		return mid;
    	if(A[low] <= A[mid])
    	{
    		if(target >= A[low] && target < A[mid])
    			high = mid;
    		else
    			low = mid + 1;
    	}
    	else
    	{
    		if(target <= A[high - 1] && target > A[mid])
    			low = mid + 1;
    		else
    			high = mid;
    	}
    }
    return -1;
}
