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
    TreeNode* insert(TreeNode* root, int val) {
        TreeNode* n = new TreeNode(val);
        if(root == NULL){
            return n;
        }
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* temp = s.top();
        while(!s.empty()){
            temp = s.top();
            s.pop();
            if(temp -> val < val && temp -> right){
                s.push(temp -> right);
            }
            else if(temp -> val > val && temp -> left){
                s.push(temp -> left);
            }
            else{
                break;
            }
        }
        
        if(val > temp -> val){
            temp -> right = n;
        }
        else{
            temp -> left = n;
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++){
            insert(root, preorder[i]);
        }
        return root;
    }
};