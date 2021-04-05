// 第一遍
// 想思路
// 所有思路
// 5~10分钟
// 1. hash
//      第一次遍历, 生成val->index
//      第二次遍历, 找对应的
// 2N
// 1.1 优化
//      不用第二次遍历, 直接找到之前的匹配者(需要考虑到3,3的情况)
// N
// 时间O(N)
// 空间O(N)
// 2. 暴力法
//      一次拿i(0<= i <=n-2), 找j (i+1<= j <=n-1), 算的数值可以重复利用下.
// 时间O(N^2)
// 空间O(1)
// 3. 无了.

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> valIndexMap;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      int targetValue = target - nums[i];
      auto iter = valIndexMap.find(targetValue);
      if (iter != valIndexMap.end()) {
        int matchIndex = valIndexMap[targetValue];
        if (matchIndex == i) {
          continue;
        }
        return vector<int>{matchIndex, i};
      }
      valIndexMap[nums[i]] = i;
    }
    return vector<int>{};
  }
};