/**********************************************/
/*
 * 向量的删除操作（包括区间删除和单元素删除）
 * 其中单元素删除通过调用区间删除完成(O(n))，而反
 * 过来区间删除通过重复调用单元素删除时间复杂度为
 * O(n^2)不可取
 */
/**********************************************/
#pragma once

template<typename T> int Vector<T>::remove(Rank lo, Rank hi){ // 区间删除操作[lo, hi)
    if(lo == hi) return 0; // 考虑效率，单独处理特殊情况
    while(hi < _size){ // 将元素从前往后依次往前移动
        _elem[lo++] = _elem[hi++];
    }
    _size = lo; // 更新向量规模，丢弃[lo, _size=hi)的元素
    shrink(); // 若有必要进行空间压缩
    return hi - lo; // 返回删除元素数目
}

template<typename T> T Vector<T>::remove(Rank r){ // 单元素删除操作 0 <= r < _size
    T e = _elem[r]; // 被删除原始备份
    remove(r, r+1); // 调用区间删除算法
    return e; // 返回被删除的元素
}
