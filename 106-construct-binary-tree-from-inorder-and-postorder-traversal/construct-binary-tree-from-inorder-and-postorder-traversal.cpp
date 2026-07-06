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
 left -> root -> right
 root -> right -> left
 left -> right -> root
 */
class Solution {
public:
unordered_map<int, int> mp;
    TreeNode* helper(vector<int>& in, vector<int>& pos, int inSt, int inE, int posSt){
        if(inSt > inE){
            return nullptr;
        }

        TreeNode* root = new TreeNode(pos[posSt]);
        int mid = mp[pos[posSt]];
        int rS = inE - mid;
        root -> right = helper(in, pos, mid + 1, inE, posSt + 1);
        root -> left = helper(in, pos, inSt, mid - 1, posSt + rS + 1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i; 
        }
        reverse(postorder.begin(), postorder.end());

        return helper(inorder, postorder, 0, n - 1, 0);
    }
};