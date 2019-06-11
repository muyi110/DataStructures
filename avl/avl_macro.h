/******************************************************/
/*
 * AVL树相关的宏实现
 */
/******************************************************/
#pragma once
// 在左右孩子中取更高者
#define tallerChild(x) (stature((x)->lc) > stature((x)->rc) ? (x)->lc : (\
                        stature((x)->lc) < stature((x)->rc) ? (x)->rc : (\
                        IsLChild(*(x)) ? (x)->lc : (x)->rc))) // 等高：与父亲x同侧者(zig-zig或者zag-zag)优先
