#include "Solution.h"
using namespace std;

/**
 * NO. 15 3Sum(K sum 问题)
 * 无需序列中找出三个数字为零的组合
 * 首先排序，然后左右夹逼；找到一个数字，剩下的数据归结为2sum问题，一头一尾左右夹逼
 * 注意：
 * 防止重复计算，选取的数如果重复（与上一个选择相同）则不计算；夹逼过程中左右限重复则跳过，继续夹逼
 * 否则会超时
 */

vector<vector<int> > threeSum(vector<int> &num) 
{
    vector<vector<int> > ret;
    if(num.size() < 3)
        return ret;
    
    sort(num.begin(), num.end());
    const int target = 0;
    
    vector<int>::iterator iter = num.begin();
    for(; iter != num.end(); iter++)
    {
        vector<int>::iterator b = iter + 1;
        vector<int>::iterator c = num.end() - 1;
        if(iter != num.begin() && *iter == *(iter-1))
            continue;
        while(b < c)
        {
            if(b > iter + 1 && *b == *(b - 1))
            {
                b++;
                continue;
            }
            if(c < num.end() - 1 && *c == *(c + 1))
            {
                c--;
                continue;
            }
            if(*iter + *b + *c < target)
                b++;
            else
            {
                if(*iter + *b + *c > target)
                    c--;
                else
                {
                    vector<int> ivec;
                    ivec.push_back(*iter);
                    ivec.push_back(*b);
                    ivec.push_back(*c);
                    ret.push_back(ivec);
                    b++;
                    c--;
                }
            }
        }
    }
    return ret;
}