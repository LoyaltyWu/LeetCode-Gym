// 4.3凌晨应该已经做过一遍这题, 是已经看过题解的, 应该默写过了的, 4.3做第3遍.
// 4.3 9:00
// 双指针, 往内收, 找到各自更大, 算一遍之前的water.
#include <vector>
using namespace std;
class Solution {
public:
  int trap(vector<int> &height) {
    int size = height.size();
    if (size <= 2) {
      return 0;
    }
    int left = 0;
    int maxLeft = height[left];
    int maxLeftIndex = left;
    int right = size - 1;
    int maxRight = height[right];
    int maxRightIndex = right;
    int area = 0;
    while (left < right) {
      if (height[left] < height[right]) {
        left++;
        if (maxLeft < height[left]) {
          area += bowlTrappedWater(maxLeftIndex, left, height);
          maxLeft = height[left];
        }
      } else {
        right--;
        if (maxRight < height[right]) {
          area += bowlTrappedWater(right, maxRightIndex, height);
          maxRight = height[right];
        }
      }
    }
    return area;
  }

  int bowlTrappedWater(int left, int right, vector<int> &height) {
    int minV = min(height[left], height[right]);
    int area = 0;
    for (int i = left + 1; i < right; i++) {
      area += max(minV - height[i], 0);
    }
    return area;
  }
};