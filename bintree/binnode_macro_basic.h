/*********************************************************/
/*
 * BinNode 基本宏定义
 */
/*********************************************************/
#pragma once

#define IsRoot(x)          (!((x).parent))
#define IsLChild(x)        (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x)        (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x)       (!IsRoot(x))
#define HasLChild(x)       ((x).lc)
#define HasRChild(x)       ((x).rc)
#define HasChild(x)        (HasLChild(x) || HasRChild(x))
#define HasBothChild(x)    (HasLChild(x) && HasRChild(x))
#define IsLeaf(x)          (!HasChild(x))

#define sibling(p)         (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc) // 获取兄弟节点
#define uncle(x)           (IsLChild(*((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc)
#define FromParentTo(x)    (IsRoot(x) ? this->_root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))
