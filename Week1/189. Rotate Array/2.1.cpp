// 5.4
// 勉强的3
// 思路1暴力
// 一点点移动, 每次移动, 时空O(N)
// 思路2 O(1)空间, O(N)时间的思路
// 长度n, 除以 k 得 m,
// 外循环k, 内循环m, 内循环先把末尾的记下来o,
// 从倒数第二的元素填进去倒数第一的o的位置, 最后再把o填进去第一个的位置
// 思路3 O(N)空间, O(N)时间
// 复制2个数组, 赋值.
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
            int j = (nums.size() / g) - 1;
            int curIndex = index(i, j, k, nums.size());
            int frontIndex = index(i, j - 1, k, nums.size());
            int initialJ = nums[curIndex];
            for (; j > 0; j--) {
                curIndex = index(i, j, k, nums.size());
                frontIndex = index(i, j - 1, k, nums.size());
                nums[curIndex] = nums[frontIndex];
            }
            nums[frontIndex] = initialJ;
        }
    }

    int index(int i, int j, int k, int size) {
        int result = (j * k + i + size) % size;
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