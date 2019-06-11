/************************************************/
/*
 * 无序向量的唯一化操作（时间复杂度O(n^2))
 * 若采用先sort 后按照有序向量唯一化时间复杂度为
 * O(nlogn)
 */
/************************************************/
# pragma once

template<typename T> int Vector<T>::deduplicate(){ // 返回删除元素个数
    int oldSize = _size; // 记录删除前向量规模
    Rank i = 1; // 从_elem[1]开始从前往后逐一考察元素
    while(i < _size){
        (find(_elem[i], 0, i) < 0) ? ++i : remove(i); // 在第i个元素前继中查询雷同元素
    }
    return oldSize - _size; // 返回删除元素的个数
}
