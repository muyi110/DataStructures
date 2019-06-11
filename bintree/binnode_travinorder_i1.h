/***************************************************/
/*
 * 中序遍历迭代版本1
 */
/***************************************************/
#pragma once

template <typename T> // 从当前节点出发，沿着左分支不断深入，直到没有左分支节点
static void goAlongLeftBranch(BinNodePosi(T) x, std::stack<BinNodePosi(T)>& s){
    while(x){
        s.push(x);
        x = x->lc;
    }
}

template <typename T, typename VST> void travIn_I1(BinNodePosi(T) x, VST& visit){
    std::stack<BinNodePosi(T)> s; // 辅助栈
    while(true){
        goAlongLeftBranch(x, s);
        if(s.empty())
            break;
        x = s.top();
        s.pop();
        visit(x->data);
        x = x->rc; // 转向当前节点的右子树
    }
} 

