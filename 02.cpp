#include "universal.h"

//请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution
{
  public:
    void replaceSpace(char *str, int length)
    {
        vector<char *> pos;
        char *p = str, *q = str + length;
        while (p < q)
        {
            if (*p == ' ')
                pos.push_back(p);
            ++p;
        }
        pos.push_back(q);
        char replacement[] = "%20";
        int i = pos.size() - 1;
        while (i > 0)
        {
            memcpy(pos[i - 1] + 1 + 2 * i, pos[i - 1] + 1, pos[i] - pos[i - 1] - 1);
            memcpy(pos[i - 1] - 2 + 2 * i, replacement, 3);
            i--;
        }
    }
};
