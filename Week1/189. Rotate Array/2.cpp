
// 第二遍看完默写done
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    int mk = k % size;
    if (size < 1 || mk == 0) {
      return;
    }
    int index = 0;
    int times = gcd(mk, size);
    int round = size / times;
    for (int i = 0; i < times; i++) {
      int startIndex = i;
      int startNum = nums[i];
      int nxt = nums[(i + mk * (0)) % size];
      int j = 1;
      int newNxt;
      for (; j < round; j++) {
        int nxtIndex = (i + mk * (j)) % size;
        int curIndex = (i + mk * (j - 1)) % size;
        newNxt = nums[nxtIndex];
        nums[nxtIndex] = nxt;
        nxt = newNxt;
      }
      nums[i] = nxt;
    }
  }
};

// int main() { return 0; }