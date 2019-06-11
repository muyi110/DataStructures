/**************************************************/
/*
 * 中序遍历递归版本
 */
/**************************************************/
#pragma once

template <typename T, typename VST> void travIn_R(BinNodePosi(T) x, VST& visit){
    if(!x) return; // 基础情况
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}
