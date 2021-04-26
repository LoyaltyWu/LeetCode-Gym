#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int result = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            if (prices[i + 1] - prices[i] > 0) {
                result += (prices[i + 1] - prices[i]);
            }
        }
        return result;
    }
};

int main() { return 0; }