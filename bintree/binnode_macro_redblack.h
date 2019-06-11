/*******************************************************/
/*
 * 红黑树基本宏定义
 */
/*******************************************************/
#pragma once

#define IsBlack(p)             (!(p) || (RB_BLACK == (p)->color)) // 外部节点是黑节点
#define IsRed(p)               (!IsBlack(p))
// 这里的高度是黑高度，注意和其他树的区别
#define BlackHeightUpdated(x)  ((stature((x).lc) == stature((x).rc)) &&\
                               ((x).height == (IsRed(&x) ? stature((x).lc) : stature((x).rc) + 1)))
