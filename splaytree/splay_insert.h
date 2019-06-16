/*********************************************************/
/*
 * 伸展树插入
 */
/*********************************************************/
#pragma once

template <typename T> BinNodePosi(T) SPlay<T>::insert(const T& e)
{
    if(!(this->_root))
    {
        this->_size++;
        return this->_root = new BinNode<T>(e);
    }
    if(e == search(e)->data)
        return this->_root;
    this->_size++;
    BinNodePosi(T) t = this->_root;
    if(this->_root->data < e)
    {
        t->parent = this->_root = new BinNode<T>(e, nullptr, t, t->rc); // 插入新根
        if(HasRChild(*t))
        {
            t->rc->parent = this->_root;
            t->rc = nullptr;
        }
    }
    else
    {
        t->parent = this->_root = new BinNode<T>(e, nullptr, t->lc, t);
        if(HasLChild(*t))
        {
            t->lc->parent = this->_root;
            t->lc = nullptr;
        }
    }
    this->updateHeightAbove(t);
    return this->_root; // 最后返回总有this->_root->data = e
}
