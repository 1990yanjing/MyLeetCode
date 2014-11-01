#include "Solution.h"
#include <math.h>
using namespace std;

/**
 * NO. 66 Plus One
 * 注意：
 *    vector的insert(iterator, elem) API的使用 可在任意位置(迭代器)之前插入元素！！
 */
vector<int> plusOne(vector<int> &digits)
{
    int carray = 1;
    for(int i = digits.size() - 1; i >= 0; --i)
    {
        digits[i] += carray;
        carray = digits[i] / 10;
        digits[i] = digits[i] % 10;
    }
    if(carray > 0)
        digits.insert(digits.begin(), carray);

    return digits;
}




