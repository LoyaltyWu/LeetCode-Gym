// 1. 5~10分钟想思路
// BFS
// 时间复杂度
// 空间复杂度
// 1. 倒数, 计算, 推, 没想到9-》10的问题, 想到倒推来做, 最后调转过来的法子
//
// 2. 顺数推, 无意义...不算暴力法

#include <vector>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> result(digits.size() + 1);
    int newV = digits[digits.size() - 1] + 1;
    int nxt = newV / 10;
    int cur = newV % 10;
    result[result.size() - 1] = cur;
    for (int i = digits.size() - 2; i >= 0; i--) {
      newV = nxt + digits[i];
      cur = newV % 10;
      nxt = newV / 10;
      result[i + 1] = cur;
    }
    if (nxt > 0) {
      result[0] = nxt;
    } else {
      vector<int> newResult = vector<int>(digits.size());
      for (int i = 0; i < newResult.size(); i++) {
        newResult[i] = result[i + 1];
      }
      result = newResult;
    }
    return result;
  }
};
