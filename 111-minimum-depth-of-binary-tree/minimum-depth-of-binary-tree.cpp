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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int ans = 0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr == nullptr){
                ans++;
                if(!q.empty()) q.push(nullptr);
            }
            else{
                if(!curr -> left && !curr -> right) return ans + 1;
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
        }
        return 0;
    }
};