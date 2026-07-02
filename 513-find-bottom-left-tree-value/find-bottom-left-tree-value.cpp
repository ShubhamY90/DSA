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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool hasChild = false;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            bool hasChild = false;

            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left) {
                    hasChild = true;
                    q.push(curr->left);
                }

                if (curr->right) {
                    hasChild = true;
                    q.push(curr->right);
                }
            }

            if (!hasChild) {
                for (int x : level)
                    return x;
            }
        }
        return 0;
    }
};