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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        // vector<int> currL;
        // int h = 0;
        bool isLast = false;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr){
                
                
                //currL.clear();
                if(!q.empty()) q.push(nullptr);
            }
            else{
                //currL.push_back(curr -> val);
                if(curr -> right){
                    if(isLast) return false;
                    //q.push(curr -> right);
                    if(curr -> left){
                        q.push(curr -> left);
                        q.push(curr -> right);
                    }
                    else{
                        return false;
                    }
                }
                else if(curr -> left){
                    if(isLast) return false;
                    q.push(curr -> left);
                    isLast = true;
                }
                else{
                    isLast = true;
                }
            }
        }
        return true;
    }
};