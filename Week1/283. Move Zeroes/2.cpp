// 默写done
#include <vector>
using namespace std;
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int i = 0;
    int j = -1;
    int k = -1;
    for (; i < nums.size(); i++) {
      if (nums[i] != 0) {
        if (j == -1) {
          continue;
        } else {
          swap(nums[i], nums[j]);
          j++;
        }
      } else {
        if (j == -1) {
          j = i;
        }
      }
    }
  }
};

// int main() { return 0; }