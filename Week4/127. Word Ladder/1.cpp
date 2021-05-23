// BFS
// DFS
// DOUBLE BFS
// EXAMPLE 1: beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot","log","cog"]
// EXAMPLE 2: beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot","log"]
// EXAMPLE 1:
// BFS:
// hit
// hot
// dot lot
// dog                              log
// cog(BINGO)(already return maybe) cog(BINGO)

#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string text;
    int level;
    Node(string text1 = "", int level1 = 0) // 构造函数
    {
        text = text1;
        level = level1;
    }
};

class Solution {
  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {

        set<string> wordSet;
        for (int i = 0; i < wordList.size(); i++) {
            wordSet.insert(wordList[i]);
        }
        int result = ladderLengthBFS(beginWord, endWord, wordList, wordSet);
        cout << result << endl;
        return result;
    }

    int ladderLengthBFS(string beginWord, string endWord,
                        vector<string> &wordList, set<string> wordSet) {
        set<string> visited;
        queue<Node> queueNodes;
        queueNodes.push(Node(beginWord, 1));
        while (!queueNodes.empty()) {
            Node node = queueNodes.back();
            queueNodes.pop();
            if (visited.find(node.text) != visited.end()) {
                continue;
            }
            if (visited.find(endWord) != visited.end()) {
            }
            cout << "sth:" << node.text << endl;
            visited.insert(node.text);
            for (int i = 0; i < node.text.size(); i++) {
                char c = node.text[i];
                for (int j = 0; j < 26; j++) {
                    char cc = 'a' + j;
                    if (cc == c) {
                        continue;
                    }
                    string newT = string(node.text);
                    newT = newT.replace(i, 1, string(1, cc));
                    bool exist = wordSet.find(newT) != wordSet.end();
                    bool visited2 = visited.find(newT) != visited.end();
                    if (exist && !visited2) {
                        queueNodes.push(newT);
                    }
                }
            }
        }
        return 0;
    }

    void printAll(vector<string> all) {
        for (int i = 0; i < all.size(); i++) {
            cout << all[i] << " ";
        }
        cout << endl;
        return;
    }
};

int main() {
    Solution *s = new Solution();
    vector<string> basic = {"hot", "dot", "dog", "lot", "log", "cog"};
    s->ladderLength("hit", "cog", basic);
    basic = {"hot", "dot", "dog", "lot", "log"};
    s->ladderLength("hit", "cog", basic);
    basic = {"hot", "dot", "dog"};
    s->ladderLength("hit", "dog", basic);
    // basic = {"hot", "dot", "dog", "lot", "log"};
    // s->ladderLength("hit", "hit", basic);
    // basic = {"hot", "dot", "dog", "lot", "log"};
    // s->ladderLength("hot", "hot", basic);
    basic = {"a", "b", "c"};
    s->ladderLength("a", "c", basic);
    delete s;
    return 0;
}