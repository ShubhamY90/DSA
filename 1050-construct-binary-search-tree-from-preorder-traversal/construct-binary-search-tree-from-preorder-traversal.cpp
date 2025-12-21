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
    TreeNode* helper(vector<int>& preorder, int& i, int bound){
        if(i == preorder.size() || preorder[i] > bound){
            return NULL;
        }

        TreeNode* temp = new TreeNode(preorder[i]);
        i++;
        temp -> left = helper(preorder, i, temp -> val);
        temp -> right = helper(preorder, i, bound);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};