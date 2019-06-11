/************************************************************/
/*
 * 先序遍历，迭代版本2
 */
/************************************************************/
#pragma once

template <typename T, typename VST> 
static void visitAlongLeftBranch(BinNodePosi(T) x, VST& visit, std::stack<BinNodePosi(T)>& S){
    while(x){
        visit(x->data);
        if(x->rc)
            S.push(x->rc); // 右孩子入栈
        x = x->lc; // 沿着左分支深入下一层
    }
}

template <typename T, typename VST> void travPre_I2(BinNodePosi(T) x, VST& visit){
    std::stack<BinNodePosi(T)> S; // 辅助栈
    while(true){
        visitAlongLeftBranch(x, visit, S); // 当前节点出发，逐批访问
        if(S.empty())
            return;
        x = S.top();
        S.pop();
    }
}
