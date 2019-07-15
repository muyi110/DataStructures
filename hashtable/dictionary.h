/**************************************************************/
/*
 * 字典模板类(抽象基类，提供接口)
 */
/**************************************************************/
#pragma once

template <typename K, typename V> class Dictionary
{
    virtual int size() const = 0;
    virtual bool put(K, V) = 0;
    virtual V* get(K k) = 0;
    virtual bool remove(K k) = 0;
};
