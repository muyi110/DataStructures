/***********************************************************/
/*
 * 最长公共子序列(Longest Common Subsequence)
 */
/***********************************************************/
#include <iostream>
#include <cstring>
#include <vector>

/*
 * 版本1：迭代版本
 * 时间复杂度：O(n+m)(最好情况)， O(2^n)(最坏情况)
 */
int max(int a, int b){
    return (a > b) ? a : b;
}
int LCS1(const char A[], const char B[], int n, int m){
    if (n < 0 || m < 0){ // 情况1（基准）：存在空序列，返回0
        return 0;
    }
    if (A[n] == B[m]){ //情况2：若A[n] = B[m], 则计算 LCS(A[0, n), B[0, m))，减而治之
        return LCS1(A, B, n-1, m-1) + 1;
    }
    else{ // 情况3：若 A[n] != B[m], 取LCS(A, B, n-1, m)与LCS(A, B, n, m-1)的最大者，分而治之
        return max(LCS1(A, B, n, m-1), LCS1(A, B, n-1, m));
    }
}

/*
 * 版本2：迭代版本（动态规划）
 */
int LCS2(const char A[], const char B[], int n, int m){
    std::vector<std::vector<int>> table(n+1, std::vector<int>(m+1)); // 定义一个 n*m 的表
    int max;
    for (int i = 0; i <= m; ++i){ // 填充表格第一行
        if (A[0] == B[i] || (i > 0 and table[0][i-1] == 1)) table[0][i] = 1;
        else table[0][i] = 0;
    }
    for (int j = 0; j <= n; ++j){ // 填充表格第一列
        if (A[j] == B[0] || (j > 0 and table[j-1][0] == 1)) table[j][0] = 1;
        else table[j][0] = 0;
    }
    for (int i = 1; i <= m; ++i){ // 填充表格剩余部分
        for (int j = 1; j <= n; ++j){
            max = table[j-1][i] > table[j][i-1] ? table[j-1][i] : table[j][i-1];
            if (B[i] == A[j]) table[j][i] = table[j-1][i-1] + 1;
            else table[j][i] = max;
        }
    }
    // 显示表格
    for (int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return table[n][m];
}

int main(int argc, char *argv[]){
    const char *A = "advantage";
    const char *B = "didactical";
    std::cout << "---------------递归版本-------------------" << std::endl;
    int result1 = LCS1(A, B, strlen(A)-1, strlen(B)-1);
    std::cout << result1 << std::endl;
    std::cout << "---------------迭代版本-------------------" << std::endl;
    int result2 = LCS2(A, B, strlen(A)-1, strlen(B)-1);
    std::cout << result2 << std::endl;
    return 0;
}
