/***********************************************************************/
/*
 * 红黑树的删除操作的双黑修复（3大类4种情况）
 * (符号：删除节点为 x ，x 的兄弟为 s)
 * BB-1：2次颜色翻转，2次黑高度更新，1-2次旋转，不再递归(s为黑色，s至少有一个红孩子)
 * BB-2R：2次颜色翻转，2次黑高度更新，0次旋转，不再递归(s为黑色，s的孩子都是黑色，x的父亲p为红色)
 * BB-2B：1次颜色翻转，1次黑高度更新，0次选择，需要递归(s为黑色，s的孩子都是黑色，x的父亲p为黑色)
 * BB-3：2次颜色翻转，2次黑高度更新，1次旋转，转为BB-1或BB2R(s为红色)
 */
/***********************************************************************/
#pragma once
template <typename T> void RedBlack<T>::solveDoubleBlack(BinNodePosi(T) r)
{
    BinNodePosi(T) p = r ? r->parent : this->_hot;
    if(!p) return;
    BinNodePosi(T) s = (r == p->lc) ? p->rc : p->lc;
    if(IsBlack(s)) // 兄弟节点是黑色
    {
        BinNodePosi(T) t = nullptr;
        if(IsRed(s->rc)) 
            t = s->rc;
        if(IsRed(s->lc))
            t = s->lc;
        if(t) // BB-1
        {
            RBColor oldColor = p->color;
            BinNodePosi(T) b = FromParentTo(*p) = this->rotateAt(t); // 3+4重构
            if(HasLChild(*b))
            {
                b->lc->color = RB_BLACK;
                updateHeight(b->lc);
            }
            if(HasRChild(*b))
            {
                b->rc->color = RB_BLACK;
                updateHeight(b->rc);
            }
            b->color = oldColor;
            updateHeight(b);
        }
        else // s 没有红孩子
        {
            s->color = RB_RED;
            s->height--;
            if(IsRed(p)) // BB-2R
            {
                p->color = RB_BLACK;
            }
            else // BB-2B
            {
                p->height--;
                solveDoubleBlack(p);
            }
        }
    }
    else // BB-3
    {
        s->color = RB_BLACK;
        p->color = RB_RED;
        BinNodePosi(T) t = IsLChild(*s) ? s->lc : s->rc; // t和s同侧
        this->_hot = p;
        FromParentTo(*p) = this->rotateAt(t); //转为BB-1或者BB-2R
        solveDoubleBlack(r);
    }
}
