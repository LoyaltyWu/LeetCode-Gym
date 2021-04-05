// 默写 done
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    digits[digits.size() - 1]++;
    int carry = 0;
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (carry > 0) {
        digits[i] += carry;
      }
      carry = digits[i] / 10;
      digits[i] %= 10;
    }
    if (carry == 0) {
      return digits;
    } else {
      vector<int> carried = vector<int>(digits.size() + 1);
      carried[0] = 1;
      return carried;
    }
  }
};
