#include <iostream>
#include <ctime>
#include "quickSelect.h"
#include "quickSort.h"

using namespace std;

/*
 * @brief: 产生一个随机数组，用于排序算法的输入
 * @params: A : 生成的随机数组序列
 *          n : 随机数组的元素个数
 */
void generateRandomArray(int A[], int n)
{
    int i = 0;
    srand((unsigned)time(NULL));
    while(i < n)
    {
        A[i++] = rand() % 1000000;
    }
}

void print(int A[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

bool isSorted(int A[], int n, bool flag = true)
{
    for(int i = 1; i < n; ++i)
    {
        if(flag && (A[i] < A[i-1]))
            return false;
        if(!flag && (A[i] > A[i-1]))
            return false;
    }
    return true;
}

void copyArray(int S[], int D[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        D[i] = S[i];
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "请指定输入序列的长度" << endl;
        return 0;
    }
    clock_t start, end;
    int N = stoi(argv[1]); // 随机数组的元素个数
    const int k = 6; // 返回第k个最大（最小）元素
    int *A = new int[N];
    int *B = new int[N];

    generateRandomArray(A, N);
    //print(A, N);
    copyArray(A, B, N);
    cout << "输入序列: " << N << "个" << endl;
    cout << "是否有序: " << (isSorted(A, N, true) ? "true" : "false") << endl;
    cout << "------------------------------快速排序-------------------------------" << endl;
    start = clock();
    quickSort(A, N, true);
    int elem = A[k-1];
    end = clock();
    cout << "是否有序: " << (isSorted(A, N, true) ? "true" : "false") << endl;
    cout << "第 " << k << " 个最小元素是：" << elem << endl;
    cout << "快速排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    cout << "------------------------------快速选择-------------------------------" << endl;
    start = clock();
    int elem_1 = quickSelect(B, k, 0, N-1, true);
    end = clock();
    cout << "第 " << k << " 个最小元素是：" << elem_1 << endl;
    cout << "快速选择运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    delete []B;
    delete []A;
    return 0;
}
