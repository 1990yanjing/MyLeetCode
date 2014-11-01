#include "Solution.h"
#include <iostream>
#include <map>
using namespace std;

/**
 * NO.36 Valid Sudoku
 * 验证数独题目成立，即验证列、行、一个九宫格内是否没有重复的数字
 * 思路：   
 *    为9行、9列、9个九宫格分别建立Hash表，来标志是否有重复的数字出现
 */
bool isValidSudoku(vector<vector<char> > &board) 
{
    vector<vector<int> > colChk;
    vector<vector<int> > rowChk;
    vector<vector<int> > nineChk;
    for(int i = 0;i < 10; ++i)
    {
        vector<int> temp;
        for(int j = 0; j < 10;++j)
            temp.push_back(0);
        colChk.push_back(temp);
        rowChk.push_back(temp);
        nineChk.push_back(temp);
    }
    
    for(int i = 0;i < 9; ++i)
    {
        for(int j = 0; j < 9;++j)
        {
            if(board[i][j] != '.')
            {
                int pos = board[i][j] - '0';
                if(colChk[j][pos] || rowChk[i][pos] || nineChk[getWhichCro(i, j)][pos])
                    return false;
                else
                {
                    colChk[j][pos] = 1;
                    rowChk[i][pos] = 1;
                    nineChk[getWhichCro(i, j)][pos] = 1;
                }
            }
        }
    }
    return true;
}

int getWhichCro(int i, int j)
{
    if(i >= 0 && i <= 2)
    {
        if(j >= 0 && j <= 2)
            return 1;
        if(j >= 2 && j <= 5)
            return 2;
        if(j >= 6 && j <= 8)
            return 3;
    }
    if(i >= 3 && i <= 5)
    {
        if(j >= 0 && j <= 2)
            return 4;
        if(j >= 2 && j <= 5)
            return 5;
        if(j >= 6 && j <= 8)
            return 6;
    }
    if(i >= 6 && i <= 8)
    {
        if(j >= 0 && j <= 2)
            return 7;
        if(j >= 2 && j <= 5)
            return 8;
        if(j >= 6 && j <= 8)
            return 9;
    }
}
