// 1. Two Sum
// 五遍刷题法
// 1. 5～10分钟，确认下，有没有思路
// 2. 练习/面试遍历解法。
// 3. 有，快速写
// 4. 没有，看题解
// 5. 看题解先BFS，再DFS
// 6. 默写，第二遍。
// 7. 第三遍第二天写
// 8. 第四遍一周之后写
// 9. 第五遍面试之前复习的时候写
// 10. 面试要达到能背出来的程度而不是还要想。
// 11. Headline法

// 五遍刷题法
// 第三次DONE

//  思路
// 1. 暴力法
// 时 N^2
// 空 1
// 2. hash
// 时 N
// 空 N
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int i = 0;
    map<int, int> mp;
    for (; i < nums.size(); ++i) {
      int v = nums[i];
      int tv = target - v;
      auto iter = mp.find(tv);
      if (iter != mp.end()) {
        return {mp[tv], i};
      }
      mp[v] = i;
    }
    return {};
  }
};