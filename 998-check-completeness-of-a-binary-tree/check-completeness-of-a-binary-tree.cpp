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
1. my approach check is the element pushed was last 
    if the curr node has right and no left return false
    if the current node has only left then this left is the last element
    now if any further node is seen left or right to any other node return false

2. second approach is just pushing null also any where null is pushed then all  
    the further should also be null otherwise return false
*/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool seenNull = false;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr){
                seenNull = true;
            }
            else{
                if(seenNull) return false;

                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};