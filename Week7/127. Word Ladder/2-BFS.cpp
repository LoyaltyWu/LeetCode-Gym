// BFS
// double BFS
// A *

// BFS
// void BFS(Node *node) {
//     queue<Node *> queue;
//     queue.push(node);
//     while (!queue.empty()) {
//         Node *cur = queue.pop();
//         // process current node
//         if (cur->children.size() > 0) {
//             queue.push(cur->children);
//         }
//     }
//     return;
// }

#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// BFS

struct Node {
  public:
    int level;
    string word;
    Node(int lv, string wd) {
        level = lv;
        word = wd;
    }
};

class Solution {
  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        // BFS
        queue<Node> wordQueue;
        set<string> wordSet;
        set<string> unvisited;
        for (int i = 0; i < wordList.size(); i++) {
            string word = wordList[i];
            wordSet.insert(word);
            unvisited.insert(word);
        }
        int foundLevel = 0;
        wordQueue.push(Node(1, beginWord));
        while (!wordQueue.empty()) {
            auto node = wordQueue.front();
            auto word = node.word;
            auto curLevel = node.level;
            wordQueue.pop();
            if (word == endWord) {
                foundLevel = curLevel;
                break;
            }
            for (int j = 0; j < word.length(); j++) {
                char curChar = word.c_str()[j];
                for (int i = 0; i < 26; i++) {
                    char c = 'a' + i;
                    if (c == curChar) {
                        continue;
                    }
                    string sc = string(1, c);
                    string copy = string(word);
                    copy.replace(copy.begin() + j, copy.begin() + j + 1, sc);
                    if (unvisited.find(copy) != unvisited.end()) {
                        unvisited.erase(copy);
                        wordQueue.push(Node(curLevel + 1, copy));
                    }
                }
            }
        }
        return foundLevel;
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
    vs = {"a", "b", "c"};
    s->ladderLength("a", "c", vs);
    delete s;
    return 0;
}