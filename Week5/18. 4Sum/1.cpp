// 思路1
// DFS + 不重复（暴力）
// 空间 N
// 时间 2^N
// 思路2
// BFS + 不重复（暴力）
// 空间 N
// 时间 2^N
// 思路3
// 前3个枚举, 最后一个map + 不重复
// 时间 N^3
// 空间
// 思路4
// sort + 固定1 + 固定2 +
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        if (nums.size() < 4) {
            return vector<vector<int>>();
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 3; i++) {
            // 全大的情况, 直接结束了
            // 第一数字偏小, 跳过
            // 重复, 跳过
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                return result;
            }
            if (nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] +
                    nums[nums.size() - 1] <
                target) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 此时固定第1个数字
            for (int j = i + 1; j < nums.size() - 2; j++) {
                // 第二数字偏小, 跳过
                // 重复, 跳过
                if (nums[i] + nums[j] + nums[nums.size() - 2] +
                        nums[nums.size() - 1] <
                    target) {
                    continue;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 此时固定第2个数字
                int start = j + 1;
                int end = nums.size() - 1;
                int curIJ = nums[i] + nums[j];
                while (start < end) {
                    int attempt = curIJ + nums[start] + nums[end];
                    if (attempt == target) {
                        vector<int> result0 = vector<int>(4, 0);
                        result0[0] = nums[i];
                        result0[1] = nums[j];
                        result0[2] = nums[start];
                        result0[3] = nums[end];
                        result.push_back(result0);
                        // 重复, 跳过
                        while (start < end && nums[start] == nums[start + 1]) {
                            start++;
                        }
                        while (start < end && nums[end] == nums[end - 1]) {
                            end--;
                        }
                        start++;
                        end--;
                    } else if (attempt > target) {
                        end--;
                    } else {
                        start++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> v = {1, 0, -1, 0, -2, 2};
    s->fourSum(v, 0);
    delete s;
    return 0;
}