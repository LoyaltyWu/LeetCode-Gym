
#include <iostream>
// #include <numeric>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        if (k % nums.size() == 0 || nums.size() <= 1) {
            return;
        }
        // 思路2的做法
        // 要找gcd
        // 外层循环0 <= i < gcd(size, k)
        // 内存循环0 <= j < size/gcd
        int g = gcd(nums.size(), k);
        for (int i = 0; i < g; i++) {
            int j = (nums.size() / g);
            for (; j > 1; j--) {
                int curIndex = index(i, j, k, nums.size());
                int frontIndex = index(i, j - 1, k, nums.size());
                swap(nums[curIndex], nums[frontIndex]); // 用了swap简洁很多.
            }
        }
    }

    int index(int i, int j, int k, int size) {
        int result = ((j * k + i + size) % size + size) % size;
        return result;
    }
};

void printAll(vector<int> sth) {
    for (int i = 0; i < sth.size(); i++) {
        cout << sth[i] << ", ";
    }
    cout << endl;
}

int main() {
    vector<int> sth = {0, 1, 2, 3, 4, 5};
    Solution *solute = new Solution();
    printAll(sth);
    solute->rotate(sth, 2);
    printAll(sth);

    sth = {0};
    printAll(sth);
    solute->rotate(sth, 2);
    printAll(sth);

    sth = {0, 1, 2};
    printAll(sth);
    solute->rotate(sth, 1);
    printAll(sth);

    sth = {0, 1, 2, 3, 4};
    printAll(sth);
    solute->rotate(sth, 3);
    printAll(sth);

    delete solute;
    return 0;
}