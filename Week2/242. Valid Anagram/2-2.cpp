// 五遍刷题法
// 1. 5～10分钟，确认下，有没有思路
// 2. 练习/面试遍历解法。
// 3. 有，快速写
// 4. 没有，看题解
// 5. 看题解先BFS，再DFS
// 6. 默写，第二遍。
// 7. 第三遍第二天写
// 8. 第四遍一周之后写
// 9. 第五遍面试之前复习的时候写
// 10. 面试要达到能背出来的程度而不是还要想。
// 11. Headline法

// 五遍刷题法
// 第二遍 sort

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
};
// int main() {
//   Solution *s = new Solution();
//   bool shouldTrue = s->isAnagram("", "");
//   cout << shouldTrue << endl;
//   shouldTrue = s->isAnagram("an", "na");
//   cout << shouldTrue << endl;
//   bool shouldFalse = s->isAnagram("cat", "rat");
//   cout << shouldFalse << endl;
//   delete s;
//   return 0;
// }