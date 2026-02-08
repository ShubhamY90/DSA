/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root, bool &isBal) {
        if (!root) return 0;

        int left = height(root->left, isBal);
        int right = height(root->right, isBal);

        if (abs(left - right) > 1) {
            isBal = false;
        }

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool isBal = true;
        height(root, isBal);
        return isBal;
    }
};
