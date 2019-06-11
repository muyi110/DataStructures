#include <iostream>
#include <ctime>
#include "shellSort.h"

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
        A[i++] = rand() % 100000;
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
    int *A = new int[N];
    int *B = new int[N];
    int *C = new int[N];
    int *D = new int[N];
    int *E = new int[N];

    generateRandomArray(A, N);
    copyArray(A, B, N);
    copyArray(A, C, N);
    copyArray(A, D, N);
    copyArray(A, E, N);
    print(A, N);
    cout << "输入序列: " << N << "个" << endl;
    cout << "Shell 排序---Shell 增量" << endl;
    start = clock();
    shellSort(A, N, true, Shell);
    end = clock();
    cout << "是否有序: " << (isSorted(A, N, true) ? "true" : "false") << endl;
    cout << "Shell 排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    cout << "Shell 排序---Hibbard 增量" << endl;
    start = clock();
    shellSort(B, N, true, Hibbard);
    end = clock();
    cout << "是否有序: " << (isSorted(B, N, true) ? "true" : "false") << endl;
    cout << "Shell 排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    delete [] B;
    cout << "Shell 排序---Knuth 增量" << endl;
    start = clock();
    shellSort(C, N, true, Knuth);
    end = clock();
    cout << "是否有序: " << (isSorted(C, N, true) ? "true" : "false") << endl;
    cout << "Shell 排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    delete [] C;
    cout << "Shell 排序---Sedgewick 增量" << endl;
    start = clock();
    shellSort(D, N, true, Sedgewick);
    end = clock();
    cout << "是否有序: " << (isSorted(D, N, true) ? "true" : "false") << endl;
    cout << "Shell 排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    delete [] D;
    cout << "Shell 排序--- 增量" << endl;
    start = clock();
    shellSort(E, N, true, Other);
    end = clock();
    cout << "是否有序: " << (isSorted(E, N, true) ? "true" : "false") << endl;
    cout << "Shell 排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    delete [] E;

    delete [] A;
    return 0;
}
