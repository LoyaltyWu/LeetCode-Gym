// 思路1
// 栈
// 思路2
// 剪枝
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// 做思路2
class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n < 1) {
            return result;
        }
        result = generateParenthesisImpl(0, 0, n, "");
        return result;
    }

    vector<string> generateParenthesisImpl(int left, int right, int n,
                                           string text) {
        vector<string> result;
        if (left < n) {
            auto leftMore =
                generateParenthesisImpl(left + 1, right, n, text + "(");
            result.insert(result.end(), leftMore.begin(), leftMore.end());
        }
        if (right < left) {
            auto rightMore =
                generateParenthesisImpl(left, right + 1, n, text + ")");
            result.insert(result.end(), rightMore.begin(), rightMore.end());
        }
        if (left == n && right == n) {
            result.push_back(text);
        }
        return result;
    }

    // void printAll(vector<string> result) {
    //     cout << "result:length:" << result.size() << endl;
    //     for (int i = 0; i < result.size(); i++) {
    //         cout << result[i] << endl;
    //     }
    //     return;
    // }
};

int main() {
    Solution *s = new Solution();
    // s->printAll(s->generateParenthesis(0));
    // s->printAll(s->generateParenthesis(1));
    // s->printAll(s->generateParenthesis(3));
    delete s;
    return 0;
}