#include "Solution.h"
#include <math.h>
#include <algorithm>
#include <iostream>
#include <functional>
#include <stdlib.h>
#include <stdio.h>
#include <set>
using namespace std;

/**
 * NO. 60 Permutation Sequence
 * 求全排列中第k个排列组合
 * 算法：
 * 利用康托编码的思路,假设有n个不重复的元素,第k个排列是a1,a2,a3,...,an,那么a1是哪一个位置呢?
 * 我们把 a1 去掉,那么剩下的排列为 a2, a3, ..., an, 共计 n − 1 个元素,n − 1 个元素共有 (n − 1)! 个排列,
 * 于是就可以知道 a1 = k/(n − 1)!。
 * 同理,a2,a3,...,an 的值推导如下:
 *  k2   = k % (n − 1)! 
 *  a2   = k2 / (n − 2)!
 *      ···
 *  kn−1 = kn−2 % 2! 
 *  an−1 = kn−1 / 1!
 *  an   = 0
 *  注意：
 *    每一个an标明的是这一位置的数字在剩余有序序列中的位置，而不是数值，所以每次确定该位置的数字后
 *    应将，该数字从整个有序序列中删除。其余的为剩余有序序列
 */
string getPermutation(int n, int k)
{
    string ret = "";
    vector<int> nums;
    for(int i = 0; i < n; ++i)
        nums.push_back(i + 1);
    
    int curk = k - 1, curN = n;
    int base = factorial(curN - 1);
    int i = n - 1;
    while(i > 0)
    {
        int a = nums[curk / base];//计算当前剩余序列中的位置，从而从nums中得出该位置的数字
        char tmp[10];
        sprintf(tmp, "%d", a);
        ret += tmp;
        curk = curk % base;
        base = base / i;//序列缩小
        i--;
        nums.erase(find(nums.begin(), nums.end(), a));//删除已经确定的数字
    }
    char tmp[10];
    sprintf(tmp, "%d", nums[0]);
    ret += tmp;
    return ret;
}

int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

