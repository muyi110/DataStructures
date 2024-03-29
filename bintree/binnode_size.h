/***************************************************************/
/*
 * 获取当前节点后代规模，即以其为根的子树规模
 */
/***************************************************************/
#pragma once

template <typename T> int BinNode<T>::size(){
    int s  = 1; // 包括当前节点本身
    if(lc){
        s += lc->size();
    }
    if(rc){
        s += rc->size();
    }
    return s;
}
