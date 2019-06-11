#include <iostream>
#include "vector.h"

using namespace std;

template <typename T> void visit(T& a){
    a = a + 10;
}
template <typename T> struct Visit{
    void operator()(T& a){
        a += 20;
    }

};

int main(int argc, char* argv[]){
    int array[5] = {2, 1, 4, 7, 3};
    Vector<int> testVector(array, 5);
    cout << "------------vector 初始化-------------" << endl;
    cout << "size: " << testVector.size() << endl;
    for(int i = 0; i < testVector.size(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl;
    cout << "------------插入操作测试-------------" << endl;
    testVector.insert(4); // 默认在尾部插入4
    testVector.insert(0, 10); // 在头部插入10
    for(int i = 0; i < testVector.size(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl;
    cout << "------------无序向量的查找操作-------" << endl;
    cout << testVector.find(4) << endl;; // 在整个范围查找
    cout << testVector.find(5, 1, 3) << endl; // 在区间[1, 3)查找
    cout << "------------向量是否已经排序---------" << endl;
    cout << testVector.disordered() << endl;
    cout << "------------无序向量唯一化操作-------" << endl;
    testVector.deduplicate();
    for(int i = 0; i < testVector.size(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl;
    cout << "-------------向量排序-----------------" << endl;
    cout << "vector size: " << testVector.size() << endl;
    testVector.sort();
    for(int i = 0; i < testVector.size(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl;
    cout << "------------有序向量查找操作----------" << endl;
    cout << testVector.search(10) << endl;
    cout << testVector.search(0) << endl;
    cout << "------------向量是否已经排序----------" << endl;
    cout << testVector.disordered() << endl;
    cout << "-------------有序向量唯一化操作-------" << endl;
    testVector.uniquify();
    for(int i = 0; i < testVector.size(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl;
    cout << "------------向量的删除操作------------" << endl;
    testVector.remove(0);
    for(int i = 0; i < testVector.size(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl;
    cout << "------------遍历操作------------------" << endl;
    testVector.traverse(visit);
    for(int i = 0; i < testVector.size(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl;
    Visit<int> visit;
    testVector.traverse(visit);
    for(int i = 0; i < testVector.size(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl;
    return 0;
}
