/*****************************************************************************/
/*
 * 伸展操作
 */
/*****************************************************************************/
#pragma once

template <typename NodePosi> inline void attachAsLChild(NodePosi p, NodePosi lc)
{
    p->lc = lc;
    if(lc)
        lc->parent = p;
}

template <typename NodePosi> inline void attachAsRChild(NodePosi p, NodePosi rc)
{
    p->rc = rc;
    if(rc)
        rc->parent = p;
}

template <typename T> BinNodePosi(T) SPlay<T>::splay(BinNodePosi(T) v)
{
    if(!v) return nullptr;
    BinNodePosi(T) p; // 节点v的父亲和祖父
    BinNodePosi(T) g;
    while((p = v->parent) && (g = p->parent)) // 自下而上对节点v做双层伸展
    {
        BinNodePosi(T) gg = g->parent; // 每轮之后，节点v以其曾祖父为父
        if(IsLChild(*v))
        {
            if(IsLChild(*p)) // zig-zig
            {
                attachAsLChild(g, p->rc);
                attachAsLChild(p, v->rc);
                attachAsRChild(p, g);
                attachAsRChild(v, p);
            }
            else // zig-zag
            {
                attachAsLChild(p, v->rc);
                attachAsRChild(g, v->lc);
                attachAsLChild(v, g);
                attachAsRChild(v, p);
            }
        }
        else if(IsRChild(*p)) // zag-zag
        {
            attachAsRChild(g, p->lc);
            attachAsRChild(p, v->lc);
            attachAsLChild(p, g);
            attachAsLChild(v, p);
        }
        else // zag-zig
        {
            attachAsRChild(p, v->lc);
            attachAsLChild(g, v->rc);
            attachAsRChild(v, g);
            attachAsLChild(v, p);
        }
        if(!gg) v->parent = nullptr; // 若v的曾祖父不存在，说明v是树根
        else
            (g == gg->lc) ? attachAsLChild(gg, v) : attachAsRChild(gg, v);
        this->updateHeight(g);
        this->updateHeight(p);
        this->updateHeight(v);
    } // 双层伸展结束
    if(p = v->parent) // 若p非空，额外做一次旋转
    {
        if(IsLChild(*v))
        {
            attachAsLChild(p, v->rc);
            attachAsRChild(v, p);
        }
        else
        {
            attachAsRChild(p, v->lc);
            attachAsLChild(v, p);
        }
        this->updateHeight(p);
        this->updateHeight(v);
    }
    v->parent = nullptr;
    return v;
}
