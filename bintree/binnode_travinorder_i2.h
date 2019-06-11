/***********************************************************/
/*
 * 中序遍历迭代版本2
 */
/***********************************************************/
#pragma once

template <typename T, typename VST> void travIn_I2(BinNodePosi(T) x, VST& visit){
    std::stack<BinNodePosi(T)> s; // 辅助栈
    while(true){
        if(x){
            s.push(x); // 根节点入栈
            x = x->lc; // 深入进入左子树
        }
        else if(!s.empty()){
            x = s.top();
            s.pop();
            visit(x->data);
            x = x->rc; // 深入进入当前节点右子树
        }
        else // 栈为空，遍历完成
            break;
    }
}
