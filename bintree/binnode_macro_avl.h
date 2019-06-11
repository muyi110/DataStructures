/******************************************************/
/*
 * AVL树的基本宏定义
 */
/******************************************************/
#pragma once

//#define max(x, y)         ((x) > (y) ? (x) : (y))
#define HeightUpdated(x)  ((x).height == 1 + std::max(stature((x).lc), stature((x).rc)))
#define Balanced(x)       (stature((x).lc) == stature((x).rc)) // 理想平衡条件
#define BalFac(x)         (stature((x).lc) - stature((x).rc)) // 平衡因子
#define AvlBalanced(x)    ((-2 < BalFac(x)) && (BalFac(x) < 2)) // AVL平衡条件
