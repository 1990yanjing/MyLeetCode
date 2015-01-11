#include "Solution.h"
#include <math.h>
using namespace std;

/**
 * NO. 16 3Sum Closest
 * 算法与3Sum相同，采用夹逼算法
 * 注意：
 * INT_MAX 是int最大值；用于求最小的初始值！！
 */
int threeSumClosest(vector<int> &num, int target) 
{
    if (num.size() < 3)
        return -1;
    sort(num.begin(), num.end());
    int minDiff = INT_MAX;
    int ret;

    for (int i = 0; i < num.size(); ++i) {
        if (i > 0 && num[i] == num[i - 1])
            continue;
        int j = i + 1, k = num.size() - 1;
        while (j < k) {
            if (j > i + 1 && num[j] == num[j - 1]) {
                j++;
                continue;
            }
            if (k < num.size() - 1 && num[k] == num[k + 1]) {
                k--;
                continue;
            }
            int sum = num[i] + num[j] + num[k];
            int diff = fabs(target - sum);
            if(diff < minDiff)
            {
                minDiff = diff;
                ret = sum;
            }
            
            if (sum > target)
                k--;
            else
            {
                if (sum < target)
                    j++;
                else
                    return target;
            }
        }
    }
    return ret;
}
