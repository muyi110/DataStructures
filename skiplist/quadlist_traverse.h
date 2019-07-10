/**************************************************/
/*
 * quadlist 的遍历操作
 */
/**************************************************/
#pragma once

template <typename T> void QuadList<T>::traverse(void(*visit)(T& ))
{
    QListNodePosi(T) p = header;
    while( (p = p->succ) != trailer)
        visit(p->data);
}

template <typename T>
template <typename VS> void QuadList<T>::traverse(VS& visit)
{
    QListNodePosi(T) p = header;
    while((p = p->succ) != trailer)
        visit(p->data);
}
