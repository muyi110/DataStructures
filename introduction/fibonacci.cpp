/********************************************************/
/*
 * 三种方法求 fib(n) = fib(n-1) + fib(n-2) 
 * {0, 1, 1, 2, 3, ...}
 */
/********************************************************/
#include <iostream>
#include <ctime>
/*
 * 方法1：递归版本，时间复杂度：T(n) = T(n-1) + T(n-2) + 1
 * 近似为O(2^n)；
 */
int fib1(int n){
    return (n < 2) ? n : fib1(n-1) + fib1(n-2);
}

/*
 * 方法2：线性递归方法，时间复杂度为 O(n)
 */
int fib2(int n, int *prev){
    if (n == 0){
        *prev = 1;
        return 0;
    }
    else{
        int prevPrev;
        *prev = fib2(n-1, &prevPrev);
        return prevPrev + (*prev);
    }
}

/*
 * 方法3 ：迭代的方法， 时间复杂度为 O(n)
 */
int fib3(int n){
    int f = 0, g = 1;
    while (0 < --n){
        g = g + f;
        f = g - f;
    }
    return g;
}

int main(int argc, char *argv[]){
    clock_t startTime, endTime;
    int result;
    int n = 45;
    int prev;
    std::cout << "-------------递归方法-------------"<<std::endl;
    startTime = clock();
    result = fib1(n);
    endTime = clock();
    std::cout << result << " " << ((double)(endTime - startTime))/CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "-------------线性递归方法-------------"<<std::endl;
    startTime = clock();
    result = fib2(n, &prev);
    endTime = clock();
    std::cout << result << " " << ((double)(endTime - startTime))/CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "-------------迭代方法-------------"<<std::endl;
    startTime = clock();
    result = fib3(n);
    endTime = clock();
    std::cout << result << " " << ((double)(endTime - startTime))/CLOCKS_PER_SEC << "s" << std::endl;
    return 0;
}
