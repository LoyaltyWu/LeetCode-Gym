// 589. N-ary Tree Preorder Traversal
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

// 思路1
// 递归
// 时间 N
// 空 N

#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
class Solution {
public:
  vector<int> preorder(Node *root) {
    if (root == nullptr) {
      return vector<int>();
    }
    int cur = root->val;
    vector<int> result = vector<int>(1, cur);
    vector<Node *> children = root->children;
    for (int i = 0; i < children.size(); i++) {
      vector<int> childResult = preorder(children[i]);
      result.insert(result.end(), childResult.begin(), childResult.end());
    }
    return result;
  }
};

int main() {
  Solution *s = new Solution();
  s->preorder(nullptr);
  delete s;
  return 0;
}