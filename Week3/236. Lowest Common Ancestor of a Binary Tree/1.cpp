
// Definition for a binary tree node.
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归流程默写
// terminator
// processer
// drill down
// clear if needed
// 回溯流程默写
// terminator
// drill down
// current
// combine result
// 4.17
// 第1次
// 思路1
// 回溯法
// 后续遍历, 左右子树是否各自找到pq, 左右子树各自找到pq, 则直接返回当前节点.
// 时间N
// 空间1(应该是N)
// 没思路2

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // terminator
        if (root == nullptr) {
            return nullptr;
        }
        vector<TreeNode *> result = lowestCommonAncestorRecurser(root, p, q);
        if (result.size() >= 2) {
            return result[0];
        }
        return nullptr;
    }

    /// size 0
    /// 找不到p or q
    /// size 1
    /// 找到 p / q, 结果在当前结果起码之上.
    /// size 2
    /// 找到 p, q 和 结果.
    vector<TreeNode *> lowestCommonAncestorRecurser(TreeNode *cur, TreeNode *p,
                                                    TreeNode *q) {
        // terminator
        if (cur == nullptr) {
            return vector<TreeNode *>();
        }
        // drill down
        vector<TreeNode *> left = lowestCommonAncestorRecurser(cur->left, p, q);
        if (left.size() == 2) {
            return left;
        }
        vector<TreeNode *> right =
            lowestCommonAncestorRecurser(cur->right, p, q);
        if (right.size() == 2) {
            return right;
        }
        // current processer
        bool curIsP = p == cur;
        bool curIsQ = q == cur;
        bool leftIsP = left.size() == 1 && p == left[0];
        bool leftIsQ = left.size() == 1 && q == left[0];
        bool rightIsP = right.size() == 1 && p == right[0];
        bool rightIsQ = right.size() == 1 && q == right[0];
        // comebine result

        vector<TreeNode *> result = {cur, cur};
        if ((curIsP && (rightIsQ || leftIsQ)) ||
            (curIsQ && (leftIsP || rightIsP)) ||
            (((leftIsQ && rightIsP) || (leftIsP && rightIsQ)))) {
            return result;
        } else if (left.size() == 1) {
            return left;
        } else if (right.size() == 1) {
            return right;
        } else if (curIsP || curIsQ) {

            return {cur};
        }
        return vector<TreeNode *>();
    }
};

int main() { return 0; }