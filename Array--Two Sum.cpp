#include "Solution.h"
#include <map>
using namespace std;

/**
 * NO.1 Two Sum
 * 采用哈希表，记录每个元素的位置（元素不唯一），利用find来需找另外一个加数
 * O(n)
 */
vector<int> twoSum(vector<int> &numbers, int target) 
{    
    vector<int> ret;
    map< int, vector<int> > indexMap;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        if(indexMap.find(numbers[i]) != indexMap.end())
            indexMap[numbers[i]].push_back(i + 1);
        else
        {
            vector<int> ivec;
            ivec.push_back(i + 1);
            indexMap[numbers[i]] = ivec;
        }
    }
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        int finder = target - numbers[i];
        if(indexMap.find(finder) != indexMap.end())
        {
            if(finder == numbers[i])
            {
                if(indexMap[finder].size() == 2)
                    return indexMap[finder];
            }
            else
            {
                ret.push_back(min(i + 1, indexMap[finder][0]));
                ret.push_back(max(i + 1, indexMap[finder][0]));
            }
        }
    }
    
    return ret;
}