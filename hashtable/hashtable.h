/***********************************************************/
/*
 * hashtable 模板类
 */
/***********************************************************/
#pragma once
#include "dictionary.h"
#include "entry.h"

enum EntryType {ACTIVE, DELETED};
template <typename K, typename V> struct Cell
{
    Entry<K, V>* entry;
    EntryType info;
    explicit Cell(K k, V v) : info(ACTIVE)
    {
        entry = new Entry<K, V>(k, v);
    }
};

template <typename K, typename V> class HashTable : public Dictionary<K, V>
{
public:
    HashTable(int c = 5);
    ~HashTable();

    int size() const {return N;} // 当前词条的数目
    int tableSize() const { return M;}
    Cell<K, V>** getTable() const { return ht;} // 用于test
    bool put(K, V);
    V* get(K k);
    bool remove(K k);
protected:
    void rehash(); // 再散列
    int probeForHit(const K& k);  // 沿着关键码k对应的查找链，找到词条匹配的桶 
    int probeForFree(const K& k); // 沿着关键码k对应的查找链，找到可用的空桶
private:
    int M; // 桶数组的容量
    int N; // 词条数量
    Cell<K, V>** ht; // 桶数组，每一个cell存放一个指针
};
#include "hashtable_hashcode.h"
#include "hashtable_rehash.h"
#include "hashtable_probeforhit.h"
#include "hashtable_probeforfree.h"
#include "hashtable_put.h"
#include "hashtable_get.h"
#include "hashtable_remove.h"
#include "hashtable_constructor.h"
#include "hashtable_destructor.h"
