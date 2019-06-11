/**************************************************/
/*
 * 先序遍历
 */
/**************************************************/
#pragma once
#include <stack>
#include "binnode_travpreorder_i1.h"
#include "binnode_travpreorder_i2.h"
#include "binnode_travpreorder_r.h"

template <typename T>
template <typename VST> void BinNode<T>::travPre(VST& visit){
    int m = 3;
    switch(m){
        case 1:
            travPre_I1(this, visit); // 迭代版本1
            break;
        case 2:
            travPre_I2(this, visit); // 迭代版本2
            break;
        default:
            travPre_R(this, visit); // 递归版本
            break;
    }
}
