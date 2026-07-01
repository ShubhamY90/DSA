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
    bool helper(TreeNode* root, int t, int sum){
        sum += root -> val;

        if(!root -> left && !root -> right && sum == t) return true;
        
        bool r = false;
        bool l = false;
        
        if(root -> right){
            r = helper(root -> right, t, sum);
        }
        if(root -> left){
            l = helper(root -> left, t, sum);
        }
        if(l || r) return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return helper(root, targetSum, 0);
    }
};