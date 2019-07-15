#include <iostream>
#include <vector>
#include <string>
#include "hashtable.h"

using namespace std;
int main(int argc, char* argv[])
{
    vector<string> vec{"11", "22", "33", "44", "55", "66", "77", "88", "99", "00"};
    HashTable<string, int> *hashTable = new HashTable<string, int>(29);
    cout << "表大小：" << hashTable->tableSize() << endl;
    for(string elem : vec)
    {
        hashTable->put(elem, stoi(elem));
    }
    cout << "元素个数：" << hashTable->size() << endl;
    cout << "hashtable: " << endl;
    Cell<string, int>** ht = hashTable->getTable();
    for(int i = 0; i < hashTable->tableSize(); ++i)
    {
        if(ht[i])
            cout << ht[i]->entry->value() << " ";
    }
    cout << endl;
    cout << "-------------------hashtable 查找------------------" << endl;
    cout << "查找 key=11: " << *(hashTable->get("11")) << endl;
    cout << "-------------------hashtable 查找全部元素------------------" << endl;
    for(int i = 0; i < hashTable->size(); ++i)
    {
        cout << *(hashTable->get(vec[i])) << " ";
    }
    cout << endl;
    cout << "-------------------hashtable 删除------------------" << endl;
    cout << "删除 key=11: " << endl;
    hashTable->remove("11");
    cout << "查找 key=11: " << (hashTable->get("11") ? "found" : "no found") << endl;
    cout << "表大小：" << hashTable->tableSize() << endl;
    return 0;
}
