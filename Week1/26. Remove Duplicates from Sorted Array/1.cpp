#include <iostream>
#include <vector>
using namespace std;
// 1. 想所有思路，审题
//    5～10分钟
// 思路
// 暴力法: 遍历, (注意不能增加新的空间)
// 想到什么交换, 但是没想下去.
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int length = nums.size();
    if (length <= 1) {
      return length;
    }
    int lastIndex = length - 1;
    for (int i = length - 1; i > 0; i--) {
      if (nums[i] == nums[i - 1]) {
        nums.erase(nums.begin() + i);
      }
    }
    return nums.size();
  }
};

// int main() { return 0; }