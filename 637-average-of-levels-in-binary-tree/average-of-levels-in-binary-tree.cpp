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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> currLvl;
        vector<double> ans;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr){
                ans.push_back((accumulate(currLvl.begin(), currLvl.end(), 0.0))/currLvl.size());
                currLvl.clear();
                if(!q.empty()) q.push(nullptr);
            }
            else{
                currLvl.push_back(curr -> val);
                if(curr -> left){
                    q.push(curr -> left);
                }
                if(curr -> right){
                    q.push(curr -> right);
                }
            }
        }
        return ans;
    }
};