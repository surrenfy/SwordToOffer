#include "universal.h"

//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution
{
  public:
    bool Find(int target, vector<vector<int>> array)
    {
        int line = array.size() - 1;
        int col_max = array[0].size();
        int col = 0;
        while (line >= 0 && col < col_max)
        {
            if (array[line][col] == target)
                return true;
            if (array[line][col] < target)
                ++col;
            else
                --line;
        }
        return false;
    }
}; 
