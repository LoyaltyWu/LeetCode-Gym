# 布隆过滤器、LRUCache、排序、高级动态规划

## 布隆过滤器

1. 通过哈希函数, 做一个二进制向量, 用于快速判断当前元素是否存在, 可以返回"可能存在"和"不在"两种情况, 用于缓存, 例如在数据库查险操作前面加一层布隆过滤器来挡掉一部分无意义的查数据库操作.

## LRUCache

### LRUCache 理解

1. 通过 double linked list 和 hashMap 来实现
2. 最终效果, 最近最少被查元素会被优先淘汰出缓存, 实现对经常使用的元素做一个缓存.

### LRU 代码模版

```# Python

class LRUCache(object): 

    def __init__(self, capacity): 
        self.dic = collections.OrderedDict() 
        self.remain = capacity

    def get(self, key): 
        if key not in self.dic: 
            return -1 
        v = self.dic.pop(key) 
        self.dic[key] = v   # key as the newest one 
        return v 

    def put(self, key, value): 
        if key in self.dic: 
            self.dic.pop(key) 
        else: 
            if self.remain > 0: 
                self.remain -= 1 
            else:   # self.dic is full
                self.dic.popitem(last=False) 
        self.dic[key] = value

```

## 排序

### 笔记

1. 排序分为比较和特殊的
   1. 基于比较的, 时间复杂度最优也只是 NLogN, 归并, 堆排, 快排, 比较差的有冒泡, 插入, 选择
      1. 归并能用于解决逆序对问题, 因为合并步中的填回旧数组步骤, 涉及两个排好序的数组的各自元素的大小比较, 前半数组的元素大于后半数组的情况, 都能算是逆序对.
   2. 特殊的, 针对整数的
      1. 基数(先排最末尾)
      2. 桶排序(通过映射函数, 进行初始的分桶, 桶之间的大小关系要能保证)
      3. 计数排序(数的取值范围和开辟的长度一样)

## 高级动态规划

### 递归函数模版

```#python
# terminator
# current
# drilldown
# restore status
```

### 分治函数模版

```#python
# terminator
# current
# drilldown(conquer subproblem)
# combine result
# restore status
```

### 感触

1. 人肉递归低效, 很累
2. 找到最近最简方法, 拆分成可重复的子问题
3. 数学归纳法思想

### 本质

1. 找重复性, 最小子重复问题

### 动态规划步骤

1. 将复杂问题化简成简化的子问题
2. 分治+最优子结构
3. 顺推形式：动态递推

### DP 顺推模版

```#python
def DP():
    dp = [][] # 二维的情况
    for i = 0..M {
        for j = 0..N {
            dp[i][j] = _Function(dp[i'][j']...) # 状态转移方程
        }
    }
    return dp[M][N]
```

### 关键点

1. 动态规划和递归/分治没有根本区别
2. 拥有的共性：找到重复的子问题
3. 差异性：最优子结构、中间可以淘汰次优解

### 例题

#### 爬楼梯

1. 递归公式: f(n) = f(n-1) + f(n-2) f(1) = 1, f(0) = 0

#### 不同路径

1. 递归公式: f(x,y) = f(x-1, y) + f(x, y-1) f(0,0) = 1,

#### 不同路径有障碍物的情况

TODO

#### 打家劫舍

> 不能偷相邻房子, 利益最大化

1. dp[i] = max(dp[i-2] + num[i], dp[i-1])

#### 最小路径和

1. dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + A[i][j]

#### 股票买卖团灭方程

1. dp[i][k][0 or 1] 0 <= i <= n - 1, 1 <= k <= K

   - i 为天数
   - k 为最多交易次数
   - [0,1]是否持有股票

   ```#Swift
   for i in 0..<n
       for j in 1...K
           for s in 0...1
               dp[i][k][s] = max(buy, sell, rest)// TODO补充
   ```

## 复杂动态规划

### 复杂度来源

1. 更高维度, 二维, 三维, 或者更多
2. 状态方程更加复杂

本质: 多练, 逻辑思维, 数学
