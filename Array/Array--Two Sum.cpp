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

/**
 * 2 sum 夹逼算法版本，但是不使用与leetcode的题目；题目要求记录位置；使用哈希表的方式更为合适
 * 但是没有夹逼发高效；更是3Sum以及4sum的核心算法
 */
vector<int> twoSum(vector<int> &numbers, int target) 
{    
    vector<int> ret;
    if(numbers.size() < 2)
        return ret;
    
    sort(numbers.begin(), numbers.end());
    int i = 0;
    int j = numbers.size() - 1;
    
    while(j > i)
    {
        if(i > 0 && numbers[i] == numbers[i - 1])
        {
            i++;
            continue;
        }
        if(j < numbers.size() - 1 && numbers[j] == numbers[j + 1])
        {
            j--;
            continue;
        }
        int sum = numbers[i] + numbers[j];
        if(sum > target)
            j--;
        else
        {
            if(sum < target)
                i++;
            else
            {
                ret.push_back(i + 1);
                ret.push_back(j + 1);
                return ret;
            }
        }
    }
    return ret;
}