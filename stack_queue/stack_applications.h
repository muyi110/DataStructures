#ifndef STACK_APPLICATIONS_H
#define STACK_APPLICATIONS_H
#include "stack.h"
#include <math.h>
//进制转换
void convert_with_recursive(Stack<char>& S, int n, int base);
// 迭代版本
void convert_with_iteration(Stack<char>& S, int n, int base);
// 括号匹配
bool paren(const char exp[]);
// 表达式求值
#define N_OPTR 9 //运算符总数
typedef enum {ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE} Operator; //运算符集合
//加、减、乘、除、乘斱、阶乘、左括号、右括号、起始符不终止符
const char pri[N_OPTR][N_OPTR] = { //运算符优先等级 [栈顶] [当前]
    /*          |-------------- 当前运算符 --------------| */
    /*          +    -    *    /    ^    !    (    )    \0 */
    /* -- + */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
    /* | - */  '>', '>', '<', '<', '<', '<', '<', '>', '>',
    /* 栈 * */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
    /* 顶 / */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
    /* 运 ^ */ '>', '>', '>', '>', '>', '<', '<', '>', '>',
    /* 算 ! */ '>', '>', '>', '>', '>', '>', ' ', '>', '>',
    /* 符 ( */ '<', '<', '<', '<', '<', '<', '<', '=', ' ',
    /* | ) */  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    /* -- \0 */'<', '<', '<', '<', '<', '<', '<', ' ', '='
};
float evaluate(char* S, char*& RPN);
float calcu(float a, char op, float b);
float calcu(char op, float b);
void readNumber(char*&, Stack<float>&);
Operator optr2rank(char);
char orderBetween(char, char);
void append(char*&, float);
void append(char*&, char);
#endif
