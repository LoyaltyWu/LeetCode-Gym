// 思路1
// 贪心法
// 时间: N
// 空间: 1
#include <vector>

using namespace std;

class Solution {
  public:
    bool lemonadeChange(vector<int> &bills) {
        int fives = 0;
        int tens = 0;
        for (int i = 0; i < bills.size(); i++) {
            int bill = bills[i];
            if (bill == 5) {
                fives += 1;
            } else {
                if (bill == 10) {
                    if (fives <= 0) {
                        return false;
                    }
                    tens += 1;
                    fives -= 1;
                } else if (bill == 20) {
                    if (fives <= 0) {
                        return false;
                    }
                    if (tens <= 0) {
                        if (fives < 3) {
                            return false;
                        }
                        fives -= 3;
                    } else {
                        tens -= 1;
                        fives -= 1;
                    }
                }
            }
        }
        return true;
    }
};
int main() { return 0; }