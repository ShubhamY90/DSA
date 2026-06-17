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
    int helper(TreeNode* root, bool prev, TreeNode* temp, unordered_map<TreeNode*, array<int,2>>& dp){
        if(temp == nullptr) return 0;
        if(dp.find(temp) == dp.end()) dp[temp] = {-1, -1};
        if(dp[temp][prev] != -1) return dp[temp][prev];

        int ans = 0;

        if(prev){
            ans = (helper(root, false, temp -> left, dp) + helper(root, false, temp -> right, dp));
        }
        else{
            ans = max(helper(root, false, temp -> left, dp) +  helper(root, false, temp -> right, dp), temp -> val + helper(root, true, temp -> left, dp) +  helper(root, true, temp -> right, dp));
        }
        return dp[temp][prev] = ans;

    }
    int rob(TreeNode* root) {
        TreeNode* temp = root;
        unordered_map<TreeNode*, array<int,2>> dp;
        return helper(root, false, temp, dp);
    }
};