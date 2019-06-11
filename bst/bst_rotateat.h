/***********************************************************/
/*
 * BST 节点旋转变换统一算法（3节点+ 4子树），返回调整之后局部
 * 子树根节点位置。
 * 尽管子树根会正确指向上层节点（如果存在），反向级联由上层函
 * 数完成。
 */
/***********************************************************/
#pragma once
/*
 * @params:
 *   v: 非空的孙辈节点
 */
template <typename T> BinNodePosi(T) BST<T>::rotateAt(BinNodePosi(T) v)
{
    BinNodePosi(T) p = v->parent;
    BinNodePosi(T) g = p->parent;
    if(IsLChild(*p)) // zig
    {
        if(IsLChild(*v)) // zig-zig （单旋转）
        {
            p->parent = g->parent;
            return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
        }
        else // zig-zag (双旋转)
        {
            v->parent = g->parent;
            return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
        }
    }
    else // zag
    {
        if(IsRChild(*v)) // zag-zag (单旋转)
        {
            p->parent = g->parent;
            return connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
        }
        else // zag-zig (双旋转)
        {
            v->parent = g->parent;
            return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
        }
    }
}
