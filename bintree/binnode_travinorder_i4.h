/*************************************************************/
/*
 * 中序遍历迭代版本4（不需要辅助栈和标志位）
 */
/*************************************************************/
#pragma once

template <typename T, typename VST> void travIn_I4(BinNodePosi(T) x, VST& visit){
    while(true){
        if(HasLChild(*x)){
            x = x->lc;
        }
        else{
            visit(x->data);
            while(!HasRChild(*x)){ // 不断地向上回溯
                if(!(x = x->succ())) 
                    return; // 没有后继节点，遍历完成，直接返回
                else
                    visit(x->data);
            }
            x = x->rc; // 转向非空的右子树
        }
    }
}
