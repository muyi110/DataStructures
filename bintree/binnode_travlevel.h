/**************************************************/
/*
 * 层序遍历
 */
/**************************************************/
#pragma once
#include <queue>

template <typename T> template <typename VST> void BinNode<T>::travLevel(VST& visit){
    std::queue<BinNodePosi(T)> Q; // 辅助队列
    Q.push(this); // 根节点入队
    while(!Q.empty()){
        BinNodePosi(T) x = Q.front();
        Q.pop();
        visit(x->data);
        if(HasLChild(*x))
            Q.push(x->lc); //左孩子入队
        if(HasRChild(*x))
            Q.push(x->rc); // 右孩子入队
    }
}
