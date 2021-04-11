// 242. Valid Anagram
// 五遍刷题法
// 1. 5～10分钟，确认下，有没有思路
// 2. 练习/面试遍历解法，指出所有算法的时间复杂度和空间复杂度。
// 3. 有，快速写
// 4. 没有，看题解
// 5. 看题解先BFS，再DFS
// 7. 默写，第二遍。
// 8. 第三遍第二天写
// 9. 第四遍一周之后写
// 10. 第五遍面试之前复习的时候写
// 11. 面试要达到能背出来的程度而不是还要想。
// 12. Headline法

// 五遍刷题法
// 第二遍默写（所有方法）
// 方法1 排序
// 时 NLogN
// 空 LogN取决于语言排序的实现细节
// 方法2 hash
// 时 N
// 空 S(字符集大小)
// 细节, 利用字符集做数组.
// #include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    int charCnt = 26;
    vector<int> charShowTimes(charCnt);
    for (int i = 0; i < s.length(); i++) {
      charShowTimes[s[i] - 'a']++;
      charShowTimes[t[i] - 'a']--;
    }
    for (int i = 0; i < charCnt; i++) {
      if (charShowTimes[i] != 0) {
        return false;
      }
    }
    return true;
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