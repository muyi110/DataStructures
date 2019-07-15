/*************************************************************/
/*
 * 词条模板类
 */
/*************************************************************/
#pragma once

template <typename K, typename V> class Entry
{
public:
    Entry(K k = K(), V v = V()): _key(k), _value(v){}
    Entry(const Entry<K, V> &e): _key(e.key()), _value(e.value()){}
    bool operator< (const Entry<K, V> &e){return _key < e.key();}
    bool operator> (const Entry<K, V> &e){return _key > e.key();}
    bool operator== (const Entry<K, V> &e){return _key == e.key();}
    bool operator!= (const Entry<K, V> &e){return _key != e.key();}

    const K& key() const{return _key;}
    const V& value() const{return _value;}
private:
    K _key;
    V _value;
};
