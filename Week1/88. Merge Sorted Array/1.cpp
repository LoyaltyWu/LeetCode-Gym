#include <iostream>
#include <vector>
using namespace std;

// 第一遍, 5~10分钟想思路
// 所有解法
// 时空复杂度都给出
// 解法
// 1. 两个数组，两个指针.
//      慢慢指, 一个个比大小 On空间, O(n)时间复杂
// 2. 暴力法？
//      怼着一个, ? 插入另外一个的元素? 有点强行加戏,
// 3. 排序法
//      直接弄一起, 排序. O(1)空间, O(nLog(n))时间复杂
// 4. 堆? xxxxxx

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int size1 = nums1.size();
    int j = 0;
    if (size1 <= 1) {
      while (j < n) {
        nums1[j] = nums2[j];
        j++;
      }
      return;
    }
    vector<int> result(size1);
    int i = 0;
    int k = 0;
    while (i < m && j < n) {
      int e1 = nums1[i];
      int e2 = nums2[j];
      if (e1 < e2) {
        if (i < m) {
          result[k] = nums1[i];
          i++;
          k++;
        } else {
          while (j < n) {
            result[k] = nums2[j];
            j++;
            k++;
          }
        }
      } else {
        if (j < n) {
          result[k] = nums2[j];
          j++;
          k++;
        } else {
          while (i < m) {
            result[k] = nums1[i];
            i++;
            k++;
          }
        }
      }
    }
    while (j < n) {
      result[k] = nums2[j];
      j++;
      k++;
    }
    while (i < m) {
      result[k] = nums1[i];
      i++;
      k++;
    }
    nums1 = result;
  }
};

// int main() { return 0; }