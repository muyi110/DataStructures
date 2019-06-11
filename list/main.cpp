#include <iostream>
#include "list.h"

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
    List<int> testList; // 初始化一个列表类实例
    cout << testList.size() << endl;
    cout << "--------------链表插入测试--------------" << endl;
    testList.insertAsFirst(5);
    testList.insertAsLast(7);
    testList.insertA(testList.first(), 3);
    testList.insertB(testList.last(), 6);
    testList.insertAsLast(1);
    testList.insertAsFirst(6);
    for(int i = 0; i < testList.size(); ++i){
        cout << testList[i] << " ";
    }
    cout << endl;
    cout << "-------------链表有序性判断------------" << endl;
    cout << testList.disordered() << endl;
    cout << "-------------无序链表查找--------------" << endl;
    cout << testList.find(6)->data << endl;
    cout << "-------------无序链表去重--------------" << endl;
    testList.deduplicate();
    for(int i = 0; i < testList.size(); ++i){
        cout << testList[i] << " ";
    }
    cout << endl;
    testList.insertAsLast(6);
    cout << "-------------排序----------------------" << endl;
    testList.sort();
    for(int i = 0; i < testList.size(); ++i){
        cout << testList[i] << " ";
    }
    cout << endl;
    cout << "--------------有序链表去重-------------" << endl;
    testList.uniquify();
    for(int i = 0; i < testList.size(); ++i){
        cout << testList[i] << " ";
    }
    cout << endl;
    cout << "---------------有序链表查找------------" << endl;
    cout << testList.search(2)->data << endl;
    cout << "---------------删除操作----------------" << endl;
    testList.remove(testList.first());
    for(int i = 0; i < testList.size(); ++i){
        cout << testList[i] << " ";
    }
    cout << endl;
    cout << "---------------构造初始化-------------" << endl;
    List<int> testList1 = testList;
    List<int> testList2(testList, 0, testList.size());
    List<int> testList3(testList.first(), testList.size());
    for(int i = 0; i < testList1.size(); ++i){
        cout << testList1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < testList2.size(); ++i){
        cout << testList2[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < testList3.size(); ++i){
        cout << testList3[i] << " ";
    }
    cout << endl;
    cout << "---------------链表倒置-------------" << endl;
    testList.reverse();
    for(int i = 0; i < testList.size(); ++i){
        cout << testList[i] << " ";
    }
    cout << endl;
    cout << "---------------遍历操作-------------" << endl;
    testList.traverse(visit);
    for(int i = 0; i < testList.size(); ++i){
        cout << testList[i] << " ";
    }
    cout << endl;
    Visit<int> visit;
    testList.traverse(visit);
    for(int i = 0; i < testList.size(); ++i){
        cout << testList[i] << " ";
    }
    cout << endl;

    return 0;
}
