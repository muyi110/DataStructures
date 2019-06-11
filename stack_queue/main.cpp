#include <iostream>
#include <cstring>
#include "stack_applications.h"

using namespace std;

int main(int argc, char* argv[]){
    Stack<char> stack;
    cout << "----------------进制转换操作-----------------" << endl;
    convert_with_recursive(stack, 10, 2);
    while(!stack.empty()){
        cout << stack.pop() << " ";
    }
    cout << endl;
    convert_with_iteration(stack, 10, 2);
    while(!stack.empty()){
        cout << stack.pop() << " ";
    }
    cout << endl;
    cout << "----------------括号匹配--------------------" << endl;
    char exp[] = "{[()]}";
    cout << paren(exp) << endl;
    cout << "----------------表达式求值------------------" << endl;
    char S[] = "2+4*20/10-5.5+0.5-2";
    char* rpn = (char*)malloc(sizeof(char)*1);
    rpn[0] = '\0';
    cout << evaluate(S, rpn) << endl;
    for(int i = 0; i < strlen(rpn); ++i){
        cout << rpn[i];
    }
    cout << endl;

    return 0;
}
