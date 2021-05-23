
#include <vector>
using namespace std;

class Solution {
  public:
    int jump(vector<int> &nums) {
        int result = 0;
        if (nums.size() == 1) {
            return result;
        }
        int curCover = 0;
        int nxtCover = 0;
        for (int i = 0; i < nums.size(); i++) {
            nxtCover = max(nxtCover, nums[i] + i);
            if (i == curCover) {
                if (curCover >= nums.size() - 1) {
                    return result;
                }
                result++;
                curCover = nxtCover;
                if (nxtCover >= nums.size() - 1) {
                    return result;
                }
            }
        }
        return result;
    }
};