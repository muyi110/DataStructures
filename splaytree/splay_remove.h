/************************************************************/
/*
 * 伸展树删除操作
 */
/************************************************************/
#pragma once

template <typename T> bool SPlay<T>::remove(const T& e)
{
    if(!this->_root || (e != search(e)->data))
        return false;
    BinNodePosi(T) w = this->_root;
    if(!HasLChild(*(this->_root))) // 若没有左子树，直接删除
    {
        this->_root = this->_root->rc;
        if(this->_root)
            this->_root->parent = nullptr;
    }
    else if(!HasRChild(*(this->_root))) // 没有右孩子，也直接删除
    {
        this->_root = this->_root->lc;
        if(this->_root)
            this->_root->parent = nullptr;
    }
    else // 左右子树同时存在
    {
        BinNodePosi(T) lTree = this->_root->lc;
        lTree->parent = nullptr;
        this->_root->lc = nullptr;
        this->_root = this->_root->rc;
        this->_root->parent = nullptr;
        search(w->data); // 右子树最小节点伸展到根(查找必定失败)
        this->_root->lc = lTree;
        lTree->parent = this->_root;
    }
    delete w; w = nullptr;
    this->_size--;
    if(this->_root)
        this->updateHeight(this->_root);
    return true;
}
