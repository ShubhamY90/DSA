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
    int helper(TreeNode* root, TreeNode* temp, int& ans){
        if(temp == nullptr) return 2;
        
        int l = helper(root, temp -> left, ans);
        int r = helper(root, temp -> right, ans);
        if(l == 0 || r == 0){
            ans++;
            return 1;
        }
        else if(l == 1 || r == 1){
            return 2;
        }
        else{
            return 0;
        }
    }   
    int minCameraCover(TreeNode* root) {
        TreeNode* temp = root;
        int ans = 0;
        int t = helper(root, temp, ans);
        if(t == 0) return ans + 1;
        return ans;
    }
};