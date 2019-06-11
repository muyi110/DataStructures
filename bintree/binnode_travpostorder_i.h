/*******************************************************/
/*
 * 后续遍历（迭代版本）
 */
/*******************************************************/
#pragma once

template <typename T> static void gotoHLVFL(std::stack<BinNodePosi(T)>& S){
    while(BinNodePosi(T) x = S.top()){ // 自顶向下，沿途节点依次入栈，反复检查栈顶元素
        if(HasLChild(*x)){
            if(HasRChild(*x)){ // 先入栈右孩子
                S.push(x->rc);
            }
            S.push(x->lc); // 入栈左孩子
        }
        else{
            S.push(x->rc);
        }
    }
    S.pop(); // 弹出栈顶的空元素
}

template <typename T, typename VST> void travPost_I(BinNodePosi(T) x, VST& visit){
    std::stack<BinNodePosi(T)> S; // 辅助栈
    if(x) S.push(x); // 根节点入栈
    while(!S.empty()){
        if(S.top() != x->parent){ // 判断当前节点有兄弟
            gotoHLVFL(S); // 转向右子树
        }
        x = S.top();
        S.pop();
        visit(x->data);
    }
}
