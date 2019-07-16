/***********************************************************/
/*
 * KMP 算法实现，匹配算法时间复杂度为O(n)
 * n: 为文本字符串的长度
 */
/***********************************************************/
#include <iostream>
#include <string>
#include "buildnext.h"

int kmpMatcher(std::string& pattern, std::string& text)
{
    size_t n = text.size();
    size_t m = pattern.size();
    int* nextTable = buildNext(pattern);
    int q = 0; // 匹配的文本字符串个数
    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        while(q > 0 && (pattern[q] != text[i]))
            q = nextTable[q];
        if(pattern[q] == text[i])
            q = q+1;
        if (q == m)
        {
            q = nextTable[q];
            count++;
            std::cout << "pattern occurs with shift: " << (i+1-m) << std::endl;
        }
    }
    delete [] nextTable;
    return count;
}
