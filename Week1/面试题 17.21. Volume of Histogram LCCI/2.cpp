// 夹逼找最大，如果偏小方往内收，直到双方同时到达最高点，如果某一方找到大于等于的更高点，封水。
//
#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    if (height.size() < 3) {
      return 0;
    }
    int l = 0;
    int lTopI = l;
    int lH = height[l];
    int r = height.size() - 1;
    int rTopI = r;
    int rH = height[r];
    int result = 0;
    while (l < r) {
      if (lH < rH) {
        lH = height[++l];
        if (lH >= height[lTopI]) {
          result += rained(height, lTopI, l);
          lTopI = l;
        }
      } else {
        rH = height[--r];
        if (rH >= height[rTopI]) {
          result += rained(height, r, rTopI);
          rTopI = r;
        }
      }
    }
    return result;
  }

  int rained(vector<int> &height, int startIndex, int endIndex) {
    int lH = height[startIndex];
    int rH = height[endIndex];
    int minH = min(lH, rH);
    int total = 0;
    for (int i = 1; i < (endIndex - startIndex); i++) {
      int size = minH - height[startIndex + i];
      size = size < 0 ? 0 : size;
      total += size;
    }
    return total;
  }
};