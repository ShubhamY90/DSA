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

 /*
 using same backtracking as 113 path sum 2,
 here we are finding paths from every node as root
 edit: initially were pushing all the paths to the ans but not needed so just increasing count instead of ans.push
 2: integer overflow as the values are from -1e9 to 1e9 and adding them can not be fitted in int
 */
class Solution {
public:
    int cnt = 0;
    void helper(TreeNode* root, int t, long long sum, vector<int>& temp){

        if(!root) return;

        sum += (long long)root -> val;

        temp.push_back(root -> val);

        if(sum == t){
            cnt++;
        }
        
        bool r = false;
        bool l = false;
        
        helper(root -> right, t, sum, temp);
        helper(root -> left, t, sum, temp);
        
        //Backtracking here popping the not valid elements from temp
        temp.pop_back();
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            vector<int> temp;
            helper(curr, targetSum, 0, temp);
            
            if(curr -> left){
                q.push(curr -> left);
            }
            if(curr -> right){
                q.push(curr -> right);
            }
        }
        return cnt;
    }
};