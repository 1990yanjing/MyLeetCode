#include "Solution.h"
#include <math.h>
using namespace std;

/**
 * NO. 42 Trapping Rain Water
 * 通过柱子高度，求得存水量
 * 算法：
 *   1. 扫描一遍,找到最高的柱子,这个柱子将数组分为两半; 
 *   2. 处理左边一半，从左到右遍历，获得局部的最高峰，获得局部的最高水位，减去柱子占去的部分，就是存水的部分
 *   3. 处理右边一半，从右向左遍历，同理左半部分
 */
int trap(int A[], int n)
{
    int max = 0;
    int ret = 0;
    //取得坐高柱子的位置，将数组分为两部分
    for(int i = 0; i < n; ++i)
        if(A[i] > A[max])
            max = i;
    //扫描左半边
    for(int i = 0, peak = 0; i < max; ++i)
    {
        if(A[i] > peak)
            peak = A[i];
        else
            ret += peak - A[i];
    }
    //扫描右半边
    for(int i = n - 1, peak = 0; i > max; --i)
    {
        if(A[i] > peak)
            peak = A[i];
        else
            ret += peak - A[i];
    }
    return ret;
}


