/**********************************************************/
/*
 * 中序遍历迭代版本3（不需要辅助栈）
 */
/**********************************************************/
#pragma once

template <typename T, typename VST> void travIn_I3(BinNodePosi(T) x, VST& visit){ // 辅助空间复杂度为O(1)
    bool backtrack = false; // 回溯标志位
    while(true){
        if(!backtrack && HasLChild(*x)){
            x = x->lc;
        }
        else{
            visit(x->data);
            if(HasRChild(*x)){ // 如果有右孩子，向下深入
                x = x->rc;
                backtrack = false;
            }
            else{ // 当前节点没有右孩子，向上回溯
                if(!(x = x->succ())) // 没有后继节点，遍历完成，直接返回
                    break;
                backtrack = true;
            }
        }
    }
}
