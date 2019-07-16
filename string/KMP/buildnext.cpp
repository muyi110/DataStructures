/*******************************************************/
/*
 * 根据模式串构建next表（预处理阶段）
 * 时间复杂度为O(m)(m为next表的长度)
 */
/*******************************************************/
#include <string>

/*
 * nextTable[q] = max{k:k < q, and P_k 是 P_q的后缀}
 * q: 匹配的字符串个数
 */

int* buildNext(std::string &str)
{
    size_t m = str.size(); // 模式字符串的长度
    int* nextTable = new int[m+1];
    int k = 0;
    nextTable[0] = 0; // 无效值
    nextTable[1] = 0;
    for(int q = 2; q <= m; ++q)
    {
        while(k > 0 && (str[k] != str[q-1]))
            k = nextTable[k];
        if(str[k] == str[q-1])
            k++;
        nextTable[q] = k;
    }
    return nextTable;
}
