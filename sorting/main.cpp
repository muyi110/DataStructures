#include <iostream>
#include <ctime>
#include "./insertion/insertionSort.h"
#include "./shell/shellSort.h"
#include "./merge/mergeSort.h"
#include "./quick/quickSort.h"
#include "./bucket/bucketSort.h"
#include "./heap/heapSort.h"

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
        A[i++] = rand() % 1000;
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
    int *F = new int[N];

    generateRandomArray(A, N);
    //print(A, N);
    copyArray(A, B, N);
    copyArray(A, C, N);
    copyArray(A, D, N);
    copyArray(A, E, N);
    copyArray(A, F, N);
    cout << "输入序列: " << N << "个" << endl;
    cout << "是否有序: " << (isSorted(A, N, true) ? "true" : "false") << endl;
    cout << "------------------------------插入排序-------------------------------" << endl;
    start = clock();
    insertionSort(A, N, true);
    end = clock();
    cout << "是否有序: " << (isSorted(A, N, true) ? "true" : "false") << endl;
    cout << "插入排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    cout << "------------------------------希尔排序-----------------------------" << endl;
    start = clock();
    shellSort(B, N, true);
    end = clock();
    cout << "是否有序: " << (isSorted(B, N, true) ? "true" : "false") << endl;
    cout << "希尔排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    delete [] B;
    cout << "------------------------------归并排序-------------------------------" << endl;
    start = clock();
    mergeSort(C, N, true);
    end = clock();
    cout << "是否有序: " << (isSorted(C, N, true) ? "true" : "false") << endl;
    cout << "归并排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    delete [] C;
    cout << "------------------------------快速排序-------------------------------" << endl;
    start = clock();
    quickSort(D, N, true);
    end = clock();
    cout << "是否有序: " << (isSorted(D, N, true) ? "true" : "false") << endl;
    cout << "快速排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    delete [] D;
    cout << "------------------------------桶式排序-------------------------------" << endl;
    start = clock();
    bucketSort(E, N, 1000, true);
    end = clock();
    cout << "是否有序: " << (isSorted(E, N, true) ? "true" : "false") << endl;
    cout << "桶式排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    delete [] E;
    cout << "------------------------------堆排序-------------------------------" << endl;
    start = clock();
    heapSort(F, N, true);
    end = clock();
    cout << "是否有序: " << (isSorted(F, N, true) ? "true" : "false") << endl;
    cout << "堆排序运行时间(s): " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    delete [] F;

    delete []A;
    return 0;
}
