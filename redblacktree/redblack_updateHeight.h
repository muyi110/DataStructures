/************************************************************/
/*
 * 更新红黑树的高度（黑高度）
 */
/************************************************************/
#pragma once
template <typename T> T max(const T& a, const T& b)
{
    return a > b ? a : b;
}

template <typename T> int RedBlack<T>::updateHeight(BinNodePosi(T) x)
{
    x->height = max(stature(x->lc), stature(x->rc));
    return IsBlack(x) ? x->height++ : x->height;
}
// stature(NULL) = -1
