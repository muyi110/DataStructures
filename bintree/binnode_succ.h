/*****************************************************/
/*
 * 获取节点的直接后继（可以将树看成中序遍历在水平上的
 * 投影，形成一个线性的单链表）
 */
/*****************************************************/
#pragma once

template <typename T> BinNodePosi(T) BinNode<T>::succ(){
    BinNodePosi(T) s = this; // 将后继临时指向当前节点
    if(rc){ // 若包括右孩子
        s = rc; // 直接后继在右子树中
        while(HasLChild(*s))
            s = s->lc;
    }
    else{
        while(IsRChild(*s)) // 沿着当前节点向上找
            s = s->parent;
        s = s->parent;
    }
    return s;
}
