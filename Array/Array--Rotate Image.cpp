#include "Solution.h"
#include <math.h>
using namespace std;

/**
 * NO. 48 Rotate Image
 * 将二维数组原地顺时针旋转
 * 算法：
 *    1、首先，将二维数组沿其副对角翻转
 *    2、然后，将二维数组沿水平中线翻转
 */
void rotate(vector<vector<int> > &matrix)
{
    //首先，沿副对角线翻转
    int n = matrix.size();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n - i; ++j)
            swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
    
    //然后沿水平中线翻转
    for(int i = 0; i < n / 2; ++i)
        for(int j = 0; j < n; ++j)
            swap(matrix[i][j], matrix[n - i - 1][j]);
}



