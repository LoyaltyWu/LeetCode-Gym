// 242. Valid Anagram
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
// 第一遍DONE
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    map<char, int> sMap;
    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      if (sMap.find(c) == sMap.end()) {
        sMap[c] = 1;
      } else {
        sMap[c] += 1;
      }
    }
    for (int i = 0; i < t.length(); i++) {
      char c = t[i];
      auto iter = sMap.find(c);
      if (iter == sMap.end()) {
        return false;
      } else {
        int ori = sMap[c];
        if (ori <= 0) {
          return false;
        } else if (ori == 1) {
          sMap.erase(iter);
        } else {
          ori -= 1;
          sMap[c] = ori;
        }
      }
    }
    if (sMap.size() > 0) {
      return false;
    }
    return true;
  }
};
// int main() {
//   Solution *s = new Solution();
//   cout << "should true begin" << endl;
//   bool shouldTrue = s->isAnagram("anagram", "nagaram");
//   cout << shouldTrue << endl;
//   shouldTrue = s->isAnagram("", ""); // 实际上没有这种情况.
//   cout << shouldTrue << endl;
//   cout << "should false begin" << endl;
//   bool shouldFalse = s->isAnagram("rat", "car");
//   cout << shouldFalse << endl;
//   delete s;
//   return 0;
// }