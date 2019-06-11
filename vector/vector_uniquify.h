/***************************************************/
/*
 * 有序向量的唯一化操作
 * 低效率版：从前往后逐个扫描，每次发现相同删除O(n^2)
 * 高效版：从前往后扫描直到遇到不相同元素，将其直接
 * 移动到考察点的下一个位置O(n)
 */
/***************************************************/
#pragma once
/*
template <typename T> int Vector<T>::uniquify(){ // 低效版本
    int oldSize = _size;
    int i = 1;
    while(i < _size){ // 从前往后逐个扫描
        _elem[i - 1] == _elem[i] ? remove(i) : ++i; // remove 函数更新 _size 大小
    }
    return oldSize - _size; // 返回删除原始个数
}
*/
template <typename T> int Vector<T>::uniquify(){ // 高效版本
    int i = 0, j = 0;
    while(++j < _size){ // 从前往后逐个扫描
        if(_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
    }
    _size = ++i; // 更新向量规模
    shrink(); // 如果需要对规模压缩
    return j - i; // 返回删除元素个数
}
