/*********************************************************/
/*
 * 后序遍历（递归版）
 */
/*********************************************************/
#pragma once

template <typename T, typename VST> void travPost_R(BinNodePosi(T) x, VST& visit){
    if(!x) return;
    travPost_R(x->lc, visit);
    travPost_R(x->rc, visit);
    visit(x->data);
}
