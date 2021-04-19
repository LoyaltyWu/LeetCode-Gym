#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
// 第1次
// 思路1 分治法(特殊的回溯)
// 靠preorder找出分界点, 产生根节点/当前节点
// 将inorder一分为二处理, 产生左右子树.
// 空间N^2
// 时间N^2
// 得加缓存和index才行
// 空间N
// 时间N

class Solution {
  public:
    map<int, int> inMap;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // current
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return recurser(preorder, inorder, 0, preorder.size(), 0,
                        preorder.size());
    }

    TreeNode *recurser(vector<int> &preorder, vector<int> &inorder,
                       int preStart, int preEnd, int inStart, int inEnd) {
        if (preEnd <= preStart || inEnd <= inStart) {
            return nullptr;
        }
        int curValue = preorder[preStart];
        TreeNode *cur = new TreeNode(curValue);
        if (preorder.size() > 1) {
            // drill down
            // left down
            int k = inMap[curValue];
            int leftSize = k - inStart;
            int curSize = preEnd - preStart;
            if (leftSize > 0) {
                cur->left = recurser(preorder, inorder, 1, 1 + leftSize, 0, k);
            }
            // right down
            if (preorder.size() > 1 + leftSize) {
                cur->right =
                    recurser(preorder, inorder, 1 + leftSize,
                             preStart + curSize, k + 1, inStart + curSize);
            }
        }
        // combine result
        // return
        return cur;
        ;
    }
};

int main() { return 0; }