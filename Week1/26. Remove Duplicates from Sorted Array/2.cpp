// 看完题解，第二次
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int length = nums.size();
    if (length <= 1) {
      return length;
    }
    int start = 0;
    int end = 1;
    int lastNum = nums[0];
    for (int i = 1; i < length; i++) {
      if (lastNum == nums[i]) {
        continue;
      } else {
        lastNum = nums[i];
        swap(nums[end], nums[i]);
        end++;
      }
    }
    if (end < length) {
      nums.erase(nums.begin() + end, nums.end());
    }
    return nums.size();
  }
};

// int main() { return 0; }