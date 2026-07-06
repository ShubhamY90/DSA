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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i = 1; i < n; i++){
            TreeNode* temp = new TreeNode(preorder[i]);
            TreeNode* curr = root;
            while(curr){
                if(temp -> val > curr -> val){
                    if(!curr -> right){
                        curr -> right = temp;
                        break;
                    }
                    else{
                        curr = curr -> right;
                    }
                }
                else{
                    if(!curr -> left){
                        curr -> left = temp;
                        break;
                    }
                    else{
                        curr = curr -> left;
                    }
                }
            }
        }
        return root;
    }
};