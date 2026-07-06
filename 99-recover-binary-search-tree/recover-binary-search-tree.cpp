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
    vector<pair<int, TreeNode*>> inorder;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    void helper(TreeNode* root){
        if(!root) return;

        helper(root -> left);
        inorder.push_back({root -> val, root});
        if(!prev){
            prev = root;
        }
        else if(prev -> val < root -> val){
            prev = root;
        }
        else{
            if(!first){
                first = prev;
            }
            
            second = root;
            //first = prev;
            
        }
        helper(root -> right);
        return;
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        if(first && second)
            swap(first -> val, second -> val);
        
        return;
    }
};