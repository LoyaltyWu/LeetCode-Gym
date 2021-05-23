// 3.5次, 5.4
// 思路1
// 暴力
// 思路2
// 前后指针扫描,
// 时间O(N)
// 空间O(1)
#include <vector>
using namespace std;
class Solution {
  public:
    int trap(vector<int> &height) {
        if (height.size() <= 2) {
            return 0;
        }
        int i = 0;
        int j = height.size() - 1;
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        int left = height[i];
        int right = height[j];
        int sum = 0;
        while (i < j) {
            if (height[i] < height[j]) {
                i++;
                if (left <= height[i]) { // 这里提交错了, 应该是等于
                    for (int i1 = leftIndex + 1; i1 < i;
                         i1++) { // 这里终止条件错了, 调试才发现
                        sum += (left - height[i1]);
                    }
                    leftIndex = i;
                    left = height[i];
                }
            } else {
                j--;
                if (right <= height[j]) { // 这里提交错了, 应该是等于
                    for (int i1 = rightIndex - 1; i1 > j; i1--) {
                        sum += (right - height[i1]);
                    }
                    rightIndex = j; // 这里下标复制错了, 肉眼过才发现.
                    right = height[j];
                }
            }
        }
        return sum;
    }
};

int main() { return 0; }