// 第二遍, 看题解, BFS->DFS, 之后默写

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // 默写,解决[3,3]的问题.
    int size = nums.size();
    map<int, int> mp;
    for (int i = 0; i < size; i++) {
      int v = nums[i];
      int targetValue = target - v;
      if (mp.find(targetValue) != mp.end()) {
        return vector<int>{mp[targetValue], i};
      }
      mp[v] = i;
    }
    return vector<int>{};
  }
};