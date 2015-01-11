#include "Solution.h"
#include <iostream>
using namespace std;

/**
 * NO. 18 4Sum(K sum 问题)
 * 夹逼算法
 * 注意：去重即可
 */

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > ret;
    if (num.size() < 4)
        return ret;
    sort(num.begin(), num.end());

    for (int i = 0; i < num.size() - 3; ++i) {
        if (i > 0 && num[i] == num[i - 1])
            continue;
        for (int j = i + 1; j < num.size() - 2; ++j) {
            if (j > i + 1 && num[j] == num[j - 1])
                continue;
            int k = j + 1;
            int p = num.size() - 1;
            while (k < p) {
                if (k > j + 1 && num[k] == num[k - 1]) {
                    k++;
                    continue;
                }
                if (p < num.size() - 1 && num[p] == num[p + 1]) {
                    p--;
                    continue;
                }
                int sum = num[i] + num[j] + num[k] + num[p];
                if (sum > target)
                    p--;
                else {
                    if (sum < target)
                        k++;
                    else {
                        vector<int> ivec;
                        ivec.push_back(num[i]);
                        ivec.push_back(num[j]);
                        ivec.push_back(num[k]);
                        ivec.push_back(num[p]);
                        ret.push_back(ivec);
                        k++;
                        p--;
                    }
                }
            }
        }
    }
    return ret;
}