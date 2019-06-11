/******************************************************************/
 /* 
  * 减而治之：将一个大规模问题划分为一个平凡问题和一个规模减小问题；
  * 分而治之：将一个大规模问题划分为若干的子问题（子问题规模相当）
  */ 
/******************************************************************/
/*
 * 递归时间复杂度求解：
 * （1）递归跟踪：检查每个递归实例累积时间，递归调用语句本身计入
 * 对应子实例中（适合简单问题分析）
 * （2）递推方程：T(n) = T(n-1) + O(1)(对应下面 sum_2 函数)
*/
/******************************************************************/
#include <iostream>

/* 问题1：计算任意 n 个整数之和；*/

int sum_1(int A[], int n){
    /*
     * 最常规的思路：逐个取出并累加；时间复杂度为 O(n)
     */
    int sum = 0;
    for (int i = 0; i < n; ++i){
        sum += A[i];
    } 
    return sum;
}
int sum_2(int A[], int n){
    /*
     * 采用减而治之思想，利用递归求解（将规模为 n 的问题转为规模为 n-1
     * 问题和一个常数时间操作；
     * 时间复杂度：O(n)
     */
    return (n < 1) ? 0 : sum_2(A, n-1) + A[n-1];
}
int sum_3(int A[], int lo, int hi){
    /*
     * 采用分而治之的思想，利用递归求解（将规模为 n 的问题转为两个子问题
     * 规模分别为 n/2
     * 时间复杂度：O(n)
     */
    if (lo == hi) return A[lo];
    int mi = (lo + hi) >> 1;
    return sum_3(A, lo, mi) + sum_3(A, mi + 1, hi);
}

/* 问题2：给定数组 A 将其中的原始颠倒 */

void swap (int &a, int &b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}
void reverse1(int A[], int lo, int hi){
    /*
     * 采用减而治之的思想，利用递归求解（将规模为 n 的问题转为 n-1 问题
     * 和一个常数时间操作；
     */
    if (lo < hi){
        swap(A[lo], A[hi]);
        reverse1(A, lo+1, hi-1);
    }
}
void reverse2(int A[], int lo, int hi){
    /*
     * 迭代版本
     */
    while (lo < hi){
        swap(A[lo++], A[hi--]);
    }
}

/* 问题3：给定数组 A[lo, hi) 找出最大的两个整数 A[x1] 和 A[x2]
 * 比较次数近可能少
 */

void maxTwoValue1(int A[], int lo, int hi, int &x1, int &x2){
    /* 
     * 常规的思路，时间复杂度 O(2n-3)
     */
    // 第一堂扫描，找出全局最大值位置
    x1 = lo;
    for (int i = lo+1; i < hi; ++i){
        if (A[x1] < A[i]) x1 = i;
    }
    // 第二趟扫描，扫描 x1 左边的部分 A[lo, x1)
    x2 = lo;
    for (int i = lo+1; i < x1; ++i){
        if (A[x2] < A[i]) x2 = i;
    }
    // 第三趟扫描，扫描 x1 右边的部分 A[x1, hi)
    for (int i = x1+1; i < hi; ++i){
        if (A[x2] < A[i]) x2 = i;
    }
}
void maxTwoValue2(int A[], int lo, int hi, int &x1, int &x2){
    /*
     * 通过维护两个指针 x1 和 x2 分别指向当前最大值和次大值
     * 通过一次扫描，更新指针的位置
     * 时间复杂度：O(n-1)（最好），O(2n-3)（最坏）
     */
    if (A[x1=lo] < A[x2=lo+1]) swap(x1, x2);
    for (int i = lo+2; i < hi; ++i){
        if(A[x2] < A[i]){
            if (A[x1] < A[x2 = i])
                swap(x1, x2);
        }
    }
}
void maxTwoValue3(int A[], int lo, int hi, int &x1, int &x2){
    /*
     * 采用分而治之的思想，利用递归求解
     * 时间复杂度：T(n) = 2T(n/2) + 2 <= 5n/3 - 2
     */
    if (lo + 2 == hi){ // 数组有两个元素基准情况
        if (A[lo] < A[lo+1]){
            x1 = lo + 1;
            x2 = lo;
        }
        else {
            x1 = lo;
            x2 = lo + 1;
        }
        return;
    }
    if (lo + 3 == hi){ // 数组有三个元素基准情况
        if (A[x1=lo] < A[x2=lo+1]) swap(x1, x2);
        if (A[x2] < A[lo+2]){
            if(A[x1] < A[x2=lo+2])
                swap(x1, x2);
        }
        return;
    }
    int mi = (lo + hi) / 2;
    int x1L, x2L, x1R, x2R;
    maxTwoValue3(A, lo, mi, x1L, x2L);
    maxTwoValue3(A, mi, hi, x1R, x2R);
    // 得到的两个子问题的最大值与次大值比较有两种情况
    if (A[x1L] > A[x1R]){
        x1 = x1L; x2 = (A[x2L] > A[x1R]) ? x2L : x1R;
    }
    else{
        x1 = x1R; x2 = (A[x2R] > A[x1L]) ? x2R : x1L;
    }
}

int main(int argc, char *argv[]){
    int A[] = {5, 4, 6, 2, 3, 1, 7};
    // 打印原始数组
    for (int i = 0; i < 7; ++i)
        std::cout << A[i] << " ";
    std::cout << std::endl;
    // 问题1
    int sum1 = sum_1(A, 7);
    int sum2 = sum_2(A, 7);
    int sum3 = sum_3(A, 0, 7);
    std::cout << sum1 << " " << sum2 << " " << sum3 << " " << std::endl;
    // 问题2
    reverse1(A, 0, 6);
    for (int i = 0; i < 7; ++i)
        std::cout << A[i] << " ";
    std::cout << std::endl;
    reverse2(A, 0, 6);
    for (int i = 0; i < 7; ++i)
        std::cout << A[i] << " ";
    std::cout << std::endl;
    // 问题3
    int x1=0, x2=0;
    maxTwoValue1(A, 0, 7, x1, x2);
    std::cout << A[x1] << " " << A[x2] << std::endl;
    x1 = x2 = 0;
    maxTwoValue2(A, 0, 7, x1, x2);
    std::cout << A[x1] << " " << A[x2] << std::endl;
    x1 = x2 = 0;
    maxTwoValue3(A, 0, 7, x1, x2);
    std::cout << A[x1] << " " << A[x2] << std::endl;
    return 0;
}
