#include "Solution.h"
#include <math.h>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

/**
 * NO. 31 Next Permutation
 * 找到下一个全排列
 * 算法：
 * 1、从右向左，找到第一个非递增的数据，标记为partition
 * 2、从右向左，找到第一个大于partition的数据，标记为changeNum
 * 3、交换partition和changeNum
 * 4、将ChangeNum（交换后位置）右侧的所有数据倒置
 * 
 * 注意：
 *  reverse_iterator 的用法
 *  find_if、swap、reverse等库函数、算法函数的用法
 */
void nextPermutation(vector<int> &num)
{
    next_Permutation(num.rbegin(), num.rend());
}

bool next_Permutation(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end)
{
    const vector<int>::reverse_iterator rfirst = begin;
    const vector<int>::reverse_iterator rend = end;
    
    vector<int>::reverse_iterator worker = rfirst + 1;
    
    while(worker != rend && *worker >= *(worker - 1))
        worker++;
    
    if(worker == rend)
    {
        reverse(rfirst, rend);
        return false;
    }
    
    vector<int>::reverse_iterator change = find_if(rfirst, worker, bind1st(less<int>(), *worker));
    
    swap(*change, *worker);
    
    reverse(rfirst, worker);
    
    return true;
}


