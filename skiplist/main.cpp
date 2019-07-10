#include <iostream>
#include "skiplist.h"
#include <vector>

using namespace std;

template <typename T> void print(T& q)
{
   if( q->size() <= 0 ) 
   {  
       cout << endl; 
       return; 
   }
   QuadListNode<Entry<int, char>>* curr = q->first()->pred;
   QuadListNode<Entry<int, char>>* base = q->first();
   while ( base->below ) base = base->below;
   while ( base->pred ) base = base->pred;
   for ( int i = 0; i < q->size(); i++ ) 
   {
      curr = curr->succ;
      QuadListNode<Entry<int, char>>* proj = curr;
      while ( proj->below ) proj = proj->below;
      while ( ( base = base->succ ) != proj )
         cout << "------";
      cout << curr->entry.value() << "-----";
   }
   cout << endl;
}

template <typename K, typename V> void printSkipList(SkipList<K, V> &L)
{
    L.traverse(print);
    cout << endl;
}

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));
    SkipList<int, char> L;
    cout << "--------------------执行插入操作-------------------" << endl;
    vector<char> vec = {'a', 'b', 'c', 'd', 'e', 'f'};
    for(int i = 0; i < vec.size(); ++i)
    {
        L.put(i+1, vec[i]);
    }
    cout << "level: " << L.level() << endl;
    printSkipList(L);
    cout << "--------------------执行查找操作-------------------" << endl;
    cout << "find key = 3: " << *(L.get(3)) << endl;
    cout << "--------------------执行删除操作-------------------" << endl;
    cout << "remove key = 4" << endl;
    L.remove(4);
    printSkipList(L);
    return 0;
}
