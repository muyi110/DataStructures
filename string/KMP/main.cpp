#include <iostream>
#include "kmp.h"
#include <string>

int main(int argc, char* argv[])
{
    std::string text = "ababacabacbababacacbab";
    std::string pattern = "ababaca";
    std::cout << "Text: " << text << std::endl;
    std::cout << "Patteren: " << pattern << std::endl;
    int count = kmpMatcher(pattern, text);
    std::cout << "匹配的个数：" << count << std::endl;
    return 0;
}
