// 好像课上讲过这题
// 5~10分钟思考解法
// 1. 快慢指针
//      1. i 遍历
//      2. j 定在0的位置上, 初始-1, 不为-1, 则赋他i上的新值
// 时间复杂度O(N)
// 空间复杂度O(1)
// 2. 暴力法1
//      1. 遇到非0, 不管
//      2. 遇到0, 移动后面到前面,
// 时间复杂度O(N^2)
// 空间复杂度O(1)
// 2. 暴力法2
//      1. 遇到非0, 赋值到新的数组
//      2. 遇到0不管
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <vector>
using namespace std;
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int i = 0;
    int j = -1;
    int size = nums.size();
    int v;
    for (; i < size; i++) {
      v = nums[i];
      if (j == -1) {
        if (v == 0) {
          j = i;
        }
      } else {
        if (v != 0) {
          nums[j] = v;
          j++;
        }
      }
    }
    if (j < 0) {
      return;
    }
    for (i = j; j < size; j++) {
      nums[j] = 0;
    }
  }
};