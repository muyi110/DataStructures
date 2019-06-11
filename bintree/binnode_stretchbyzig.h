/*************************************************************/
/*
 * 通过顺时针旋转，将子树x拉伸为右链
 */
/*************************************************************/
#pragma once

template <typename T> void stretchByZig(BinNodePosi(T)& x, int h){
    BinNodePosi(T) v = x;
    for(; v; v = v->rc){
        while(v->lc){
            v = v->zig();
        }
        v->height = --h; // 更新每一个节点的高度
    }
    while(x->parent)
        x = x->parent;
}
