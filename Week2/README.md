# Week 2

## Hash Table, Map, Set

// TODO: java的HashMap看完之后, 写一个小的总结.

## Tree, Binary Search Tree, 

## Heap

### Binary Heap

#### 性质

1. 插入 O(logN)
2. 删除最大 O(1)
3. 找最大 O(1)

#### 数组实现

1. 左儿子2 * i + 1
2. 右儿子2 * i + 1
3. 父节点floor((i - 1) / 2)
4. 插入
    1. 添加到末尾
    2. HeapifyUp
5. 删除max
    1. 末尾元素和max互换位置
    2. HeapifyDown