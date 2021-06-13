# 字典树、并查集、AVL、红黑树、位运算

## 字典树

### 字典树理解

1. 简单理解为 26 叉树(实际上不是)
2. 节点存着是否是末尾的标识位
3. 用于搜索的输入联想等场景

## 并查集

### 并查集操作

1. 建立各自的集合
2. 合并两个集合
3. 查找父元素/代表元素

### 并查集理解

1. 对于两者是否属于同一群组，这样子的问题，应该想到可能是并查集来解决。
2. 互为朋友之类的问题

### 并查集代码模版

```# Python

def init(p): 
    # for i = 0 .. n: p[i] = i; 
    p = [i for i in range(n)]

def union(self, p, i, j): 
    p1 = self.parent(p, i) 
    p2 = self.parent(p, j) 
    p[p1] = p2

def parent(self, p, i): 
    root = i 
    while p[root] != root: 
        root = p[root] 
    while p[i] != i: # 路径压缩
        x = i; i = p[i]; p[x] = root 
    return root
```

## 平衡二叉树(自平衡二叉树/近似平衡二叉树)

## AVL

1. 左旋 左左树 变左右
2. 右旋
3. 左右旋
   1. 先做子节点的左旋变成适用右旋的情况
   2. 再右旋
4. 右左旋

## 红黑树

### 性质

1. 高度差小于两倍最短的

## AVL 和红黑树的比较

1. AVL 读更快
2. 红黑树读写更快
3. AVL 需要更多存储，存一个 factor，红黑只需要一个 bit 即可，记录是否红
4. 红黑树在大多数语言的库中使用, 像是 C++中的 map, multimap, multiset. 而 AVL 用于对读要求比较高的数据库中.

## 位运算

1. 打掉 x 的最后一位二进制的 1:

   ```#c++
   x = x&(x-1)
   ```

2. 将 x 的右 n 位二进制位清零:

   ```#c++
   x = x & (~0<<n)
   ```