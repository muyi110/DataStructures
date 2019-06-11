/*******************************************************/
/*
 * 中序遍历头文件
 */
/*******************************************************/
#pragma once

#include <stack> // 引入标准库的栈模板
#include "binnode_travinorder_r.h"
#include "binnode_travinorder_i1.h"
#include "binnode_travinorder_i2.h"
#include "binnode_travinorder_i3.h"
#include "binnode_travinorder_i4.h"

template <typename T>
template <typename VST> void BinNode<T>::travIn(VST& visit){
    int m = 3;
    switch(m){
        case 1:
            travIn_I1(this, visit); // 迭代版本1
            break;
        case 2:
            travIn_I2(this, visit); // 迭代版本2
            break;
        case 3:
            travIn_I3(this, visit); // 迭代版本3
            break;
        case 4:
            travIn_I4(this, visit); // 迭代版本4
            break;
        default:
            travIn_R(this, visit); // 递归版本
    }
}

