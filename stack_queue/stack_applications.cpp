/*************************************************/
/*
 * 栈的应用
 */
/*************************************************/
#include "stack_applications.h"
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
//进制转换
void convert_with_recursive(Stack<char>& S, int n, int base){ // 递归版本
    /*
     * n: 要转换的十进制数
     * base: 要转换目标进制的基
     */
    // 要转换目标进制下的数位符号
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    if(0 < n){
        S.push(digit[n % base]);
        convert_with_recursive(S, n / base, base);
    }
}

void convert_with_iteration(Stack<char>& S, int n, int base){ // 迭代版本
    // 要转换目标进制下的数位符号
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while(0 < n){
        int remainder = (int)(n % base); // 余数
        S.push(digit[remainder]);
        n /= base;
    }
}

// 括号匹配
bool paren(const char exp[]){
    Stack<char> S;
    for(int i = 0; exp[i]; ++i){ // 逐一检查当前字符
        switch (exp[i]){ // 左括号入栈，右括号与栈顶元素比较
            case '(': 
            case '[': 
            case '{': 
                S.push(exp[i]); 
                break;
            case ')':
                if((S.empty()) || ('(' != S.pop()))
                    return false;
                break;
            case ']':
                if((S.empty()) || ('[' != S.pop()))
                    return false;
                break;
            case '}':
                if((S.empty()) || ('{' != S.pop()))
                    return false;
                break;
            default:
                break;
        }
    }
    return S.empty(); // 扫描结束后，若栈为空，说明匹配
}

 // 表达式求值
float evaluate(char* S, char*& RPN){ // 对表达式（已删除空白）S求值，并转换为逆波兰表达式RPN
    Stack<float> opnd; // 运算数栈
    Stack<char> optr; // 运算符栈
    char op;
    float pOpnd, pOpnd1, pOpnd2;
    optr.push('\0'); // 尾哨兵首先入栈
    while(!optr.empty()){ // 在运算符栈非空之前，逐个处理表达式中字符
        if(isdigit(*S)){ // 判断当前字符是否是操作数
            readNumber(S, opnd);
            append(RPN, opnd.top());
        }
        else{
            switch (orderBetween(optr.top(), *S)){ // 比较与栈顶运算符之间的优先级
                case '<': // 栈顶运算符优先级低
                    optr.push(*S); // 运算符直接入栈
                    S++;
                    break;
                case '=': // 优先级相等（当前运算符是')'或者'\0'
                    optr.pop();
                    S++; // 直接脱括号，直接进行下一个循环
                    break;
                case '>': // 栈顶运算符的优先级高，进行计算，将结果入栈
                    op = optr.pop();
                    append(RPN, op); // 将栈顶运算符接到RPN末尾
                    if('!' == op){ // 一元运算符号
                        pOpnd = opnd.pop(); // 取出一个操作数
                        opnd.push(calcu(op, pOpnd)); // 将计算结果入栈
                    }
                    else{ // 二元运算符
                        pOpnd2 = opnd.pop();
                        pOpnd1 = opnd.pop();
                        opnd.push(calcu(pOpnd1, op, pOpnd2)); //将计算结果入栈
                    }
                    break;
                default: // 语法错误，直接退出
                    exit(-1);
            }
        }
    }
    return opnd.pop();
}
Operator optr2rank(char op){ // 将运算符转为对应的编号
    switch(op){
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        case '^':
            return POW;
        case '!':
            return FAC; // 阶乘
        case '(':
            return L_P;
        case ')':
            return R_P;
        case '\0':
            return EOE;
        default: // 未知运算符
            exit(-1);
    }
}
char orderBetween(char op1, char op2){ // 比较两个运算符的优先级
    return pri[optr2rank(op1)][optr2rank(op2)]; // pri 是优先级表
}
float calcu(float a, char op, float b){
    switch (op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if(0 == b) exit(-1); // 考虑到精度的问题，判断浮点数为0可能不安全
            return a / b;
        case '^':
            return pow(a, b);
        default:
            exit(-1);
    }
}
int facI(int n){ // 迭代方法计算阶乘
    int f = 1;
    while(1 < n){
        f *= n--;
    }
    return f;
}
float calcu(char op, float b){
    switch (op){
        case '!':
            return (float) facI((int)b);
        default:
            exit(-1);
    }
}
void readNumber(char*& p, Stack<float>& stk){ // 将起始于p的子串解释为数值，存入操作数栈中
    stk.push((float)(*p - '0')); // 当前的数值直接进栈
    while(isdigit(*(++p))){ // 存在多位数字的情况
        stk.push(stk.pop()*10 + (*p - '0')); // 弹出原数字，计算新操作数，入栈
    }
    if('.' != *p) return;
    float fraction = 1; // 处理小数部分
    while(isdigit(*(++p))){
        stk.push(stk.pop() + (*p - '0') * (fraction /= 10));
    }
}
void append(char*& rpn, float opnd){ // 将操作数追加到rpn结尾
    int n = strlen(rpn); // strlen 函数返回字符数组的长度，不包括空字符 
    char buf[64];
    // sprintf的作用是将一个格式化的字符串输出到一个目的字符串中
    if(opnd != (float)(int)opnd) sprintf(buf, "%.2f ", opnd);
    else sprintf(buf, "%d ", (int)opnd);
    rpn = (char*)realloc(rpn, sizeof(char)*(n+strlen(buf) + 1));
    strcat(rpn, buf);
}
void append(char*& rpn, char optr){ // 将运算符添加到RPN的结尾
    int n = strlen(rpn);
    rpn = (char*) realloc(rpn, sizeof(char)*(n+2)); // 注意这里是加2（官方例程是加3）
    sprintf(rpn + n, "%c", optr);
    rpn[n + 1] = '\0'; // 注意这里加1（官方例程是加2）
}
