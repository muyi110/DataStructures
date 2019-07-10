/************************************************************/
/*
 * 跳转表模板类
 */
/************************************************************/
#pragma once

#include "../list/list.h"
#include "entry.h"
#include "quadlist.h"
#include "dictionary.h"

template <typename K, typename V>
class SkipList : public Dictionary<K, V>, public List<QuadList<Entry<K, V>>*>
{
protected:
    bool skipSearch(ListNode<QuadList<Entry<K, V>>*>* &qlist, QuadListNode<Entry<K, V>>* &p, K& k);
public:
    int size() const {return this->empty() ? 0 : this->last()->data->size();} // 底层quadlist的规模
    int level() {return List<QuadList<Entry<K, V>>*>::size();}
    bool put(K, V);
    V* get(K k);
    bool remove(K k);
};
#include "skiplist_get.h"
#include "skiplist_put.h"
#include "skiplist_remove.h"
#include "skiplist_skipSearch.h"
