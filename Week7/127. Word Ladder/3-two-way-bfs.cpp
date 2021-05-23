// BFS
// two-way BFS
// A *

// two-way BFS

#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
// two-way BFS
// q1.push(node);
// q2.push(node);
// while(q1.isNotEmpty() && q2.isNotEmpty()) {
// if (q1.size() > q2.size()) {
// swap(q1, q2)
// q1 small size
// q3 = q1.copy
// q1.clear()
// while(q3.isNotEmpty) {
// node3 = q3.pop()
// q1.add(node3.children)
// }
// }
// }

struct Node {
  public:
    int level = 0;
    string word = "";
    Node(int nLevel, string theWord) {
        level = nLevel;
        word = theWord;
    }
};

class Solution {
  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        queue<string> q1;
        queue<string> q2;
        set<string> visited1;
        set<string> visited2;
        set<string> wordSet;
        for (int i = 0; i < wordList.size(); i++) {
            string word = wordList[i];
            wordSet.insert(word);
        }
        q1.push(beginWord);
        visited1.insert(beginWord);
        if (wordSet.find(endWord) != wordSet.end()) {
            q2.push(endWord);
            visited2.insert(endWord);
        } else {
            return 0;
        }
        int count = 1;
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() == 0 || q2.size() == 0) {
                return 0;
            }
            if (q1.size() > q2.size()) {
                queue<string> q3 = q1;
                set<string> visited3 = visited1;
                q1 = q2;
                q2 = q3;
                visited1 = visited2;
                visited2 = visited3;
            }
            queue<string> q4;
            while (!q1.empty()) {
                string cur = q1.front();
                q1.pop();
                visited1.insert(cur);
                for (int i = 0; i < cur.length(); i++) {
                    char c = cur.at(i);
                    for (int j = 0; j < 26; j++) {
                        string copy = string(cur);
                        char newChar = 'a' + j;
                        if (newChar == c) {
                            continue;
                        }
                        string charStr = string(1, newChar);
                        copy.replace(copy.begin() + i, copy.begin() + i + 1,
                                     charStr);
                        if (wordSet.find(copy) == wordSet.end()) {
                            continue;
                        }
                        if (visited1.find(copy) == visited1.end()) {
                            q4.push(copy);
                            visited1.insert(copy);
                        }
                        if (visited2.find(copy) != visited2.end()) {
                            return count + 1; // 探查未来的子节点是否访问.
                        }
                    }
                }
            }
            q1 = q4;
            count++; // 当前层结束了, 无效果, 那么下一层.
        }
        return 0;
    }
};

int main() {
    Solution *s = new Solution();
    vector<string> vs = {"hot", "dot", "dog", "lot", "log", "cog"};
    s->ladderLength("hit", "cog", vs);
    vs = {"hot", "dot", "dog", "lot", "log", "cog"};
    s->ladderLength("hit", "big", vs);
    vs = {"hot", "dog", "dot"};
    s->ladderLength("hot", "dog", vs);
    vs = {"hot", "cog", "dog", "tot", "hog", "hop", "pot", "dot"};
    s->ladderLength("hot", "dog", vs);
    vs = {"a", "b", "c"};
    s->ladderLength("a", "c", vs);
    delete s;
    return 0;
}