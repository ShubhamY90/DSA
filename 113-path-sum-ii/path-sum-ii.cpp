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
    vector<vector<int>> ans;
    void helper(TreeNode* root, int t, int sum, vector<int>& temp){

        if(!root) return;

        sum += root -> val;

        temp.push_back(root -> val);

        if(!root -> left && !root -> right && sum == t){
            ans.push_back(temp);
        }
        
        bool r = false;
        bool l = false;
        
        helper(root -> right, t, sum, temp);
        helper(root -> left, t, sum, temp);
        
        //Backtracking here popping the not valid elements from temp
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        helper(root, targetSum, 0, temp);
        return ans;
    }
};