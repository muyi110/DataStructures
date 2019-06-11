/******************************************************/
/*
 * 先序遍历（迭代版本1）
 */
/******************************************************/
#pragma once

template <typename T, typename VST> void travPre_I1(BinNodePosi(T) x, VST& visit){
    std::stack<BinNodePosi(T)> S; // 辅助栈
    if(x) S.push(x); // 根节点入栈
    while(!S.empty()){
        x = S.top();
        S.pop();
        visit(x->data);
        if(HasRChild(*x)){
            S.push(x->rc);
        }
        if(HasLChild(*x)){
            S.push(x->lc);
        }
    }
}
