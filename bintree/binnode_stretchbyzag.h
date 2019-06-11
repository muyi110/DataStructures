/**************************************************/
/*
 * 通过zag旋转，将字树x拉伸为左向单链
 */
/**************************************************/
#pragma once

template <typename T> void stretchByZag(BinNodePosi(T)& x){
    int h = 0;
    BinNodePosi(T) p = x;
    while(p->rc){ // 最终p指向最大节点，必是拉伸后的根
        p = p->rc;
    }
    while(x->lc){ // x指向最小节点，必为拉伸后的叶
        x = x->lc;
    }
    x->height = h++;
    for(; x != p; x = x->parent, x->height = h++){
        while(x->rc){ // x右子树为空，上升一层
            x->zag();
        }
    }
}
