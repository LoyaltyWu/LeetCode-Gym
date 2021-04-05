// 第一遍想思路
// 5～10分钟
// 1. 暴力法
//      循环赋值交换, 空间复杂度1, 时间复杂度 k*N
// 2. 开一个数组
//      mod, 赋值, 空间复杂度N, 时间复杂度n
// 3. 类似暴力法
//      移除前面的元素, 拼到后面去.k*N
// 4. 类似双指针?
//      貌似只能在符合的时候才有用, 有点特殊而已, 空间复杂度1, 时间复杂度N,
//      没想出来
// 第二遍看完默写done
#include <iostream>
#include <vector>
using namespace std;
// 解法3
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    int switchLength = k % size;
    if (size < 1 || switchLength == 0) {
      return;
    }
    vector<int> newNums(size);
    for (int i = 0; i < size; i++) {
      int newIndex = (switchLength + i) % size;
      newNums[newIndex] = nums[i];
    }
    for (int i = 0; i < size; i++) {
      nums[i] = newNums[i];
    }
  }
};

// int main() { return 0; }