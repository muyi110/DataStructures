/***********************************************************/
/*
 * 后续遍历
 */
/***********************************************************/
#pragma once
#include <stack>
#include "binnode_travpostorder_i.h"
#include "binnode_travpostorder_r.h"

template <typename T>
template <typename VST> void BinNode<T>::travPost(VST& visit){
    int m = 0;
    switch(m){
        case 1:
            travPost_I(this, visit); // 迭代版本
            break;
        default:
            travPost_R(this, visit); // 递归版本
            break;
    }
}
