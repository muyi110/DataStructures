#include <iostream>
/*************************************************************/
/*
 *问题：给定的 n 个整数中，将他们按序排序；
 *观察：在无序的序列中，总有一对相邻元素逆序；
 *起泡排序思想：依次比较相邻元素，若是逆序则交换，若整趟扫描
                没有逆序则排序完成，否则继续扫描交换
 *时间复杂度：O(n^2)
*/
/************************************************************/
void swap (int &a, int &b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void bubbleSort_0A(int A[], int n){ // 蛮力解法，不能提前退出
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(A[j] < A[i]){
                swap(A[j], A[i]);
            }
        }
    }
}

void bubbleSort_0B(int A[], int n){ //蛮力解法，不能提前退出
    while(n--){
        for(int i = 0; i < n; ++i){
            if(A[i] > A[i+1]){
                swap(A[i], A[i+1]);
            }
        }
    }
}

void bubbleSort_1A(int A[], int n){ // 借助bool型变量可以提前退出
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(int i = 1; i < n; ++i){
            if(A[i-1] > A[i]){
                swap(A[i-1], A[i]);
                sorted = false;
            }
        }
        --n; // 缩短问题规模
    }
}

void bubbleSort_1B(int A[], int n){ // 和版本1A完全等价
    bool sorted = false; // 排序完成标志
    for (sorted; sorted = !sorted; --n){ // 逐趟扫描，最多扫描 n 次，每趟扫描后最大值必然就位
        for (int i=1; i < n; ++i){
            if (A[i-1] > A[i]){ // 如果存在逆序对
                swap(A[i-1], A[i]);
                sorted = false; // 排序未完成
            }
        }
    }
}

void bubbleSort_2(int A[], int n){ // 借助m尽快收缩问题规模
    for(int m; 1 < n; n = m){
        for(int i = m = 1; i < n; ++i){
            if(A[i-1] > A[i]){
                swap(A[i-1], A[i]);
                m = i; // 更新问题规模
            }
        }
    }
}

int main (int argc, char *argv[]){
    int A[7] = {5, 2, 7, 4, 6, 3, 1};
    // 打印原始数组数据
    for (int i = 0; i < 7; ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl; //换行
    // 排序
    bubbleSort_0A(A, 7);
    // 打印排序后的数组数据
    for (int i = 0; i < 7; ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl; //换行
    int B[7] = {5, 2, 7, 4, 6, 3, 1};
    // 打印原始数组数据
    for (int i = 0; i < 7; ++i){
        std::cout << B[i] << " ";
    }
    std::cout << std::endl; //换行
    // 排序
    bubbleSort_0B(B, 7);
    // 打印排序后的数组数据
    for (int i = 0; i < 7; ++i){
        std::cout << B[i] << " ";
    }
    std::cout << std::endl; //换行
    int C[7] = {5, 2, 7, 4, 6, 3, 1};
    // 打印原始数组数据
    for (int i = 0; i < 7; ++i){
        std::cout << C[i] << " ";
    }
    std::cout << std::endl; //换行
    // 排序
    bubbleSort_1A(C, 7);
    // 打印排序后的数组数据
    for (int i = 0; i < 7; ++i){
        std::cout << C[i] << " ";
    }
    std::cout << std::endl; //换行
    int D[7] = {5, 2, 7, 4, 6, 3, 1};
    // 打印原始数组数据
    for (int i = 0; i < 7; ++i){
        std::cout << D[i] << " ";
    }
    std::cout << std::endl; //换行
    // 排序
    bubbleSort_1B(D, 7);
    // 打印排序后的数组数据
    for (int i = 0; i < 7; ++i){
        std::cout << D[i] << " ";
    }
    std::cout << std::endl; //换行
    int E[7] = {5, 2, 7, 4, 6, 3, 1};
    // 打印原始数组数据
    for (int i = 0; i < 7; ++i){
        std::cout << E[i] << " ";
    }
    std::cout << std::endl; //换行
    // 排序
    bubbleSort_2(E, 7);
    // 打印排序后的数组数据
    for (int i = 0; i < 7; ++i){
        std::cout << E[i] << " ";
    }
    std::cout << std::endl; //换行

    return 0;
}
