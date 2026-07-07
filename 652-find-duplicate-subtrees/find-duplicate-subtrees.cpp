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
 pahle store kar liya sabka preorder aur null ke liye # 
 sabka unique aaega postorder 
 postorder hi use kiya kyuki subtree tbhi define hoga root pe jab uske left right honge
 fir unn strings ki frequency store karli (pahle strings store kari thi fir compare kara tha)
 map store kar liya har string ka koi bhi ek root hi 
 agar baar baar string aayi tab bhi ek hi root node
 for jiski freq >= 2 thi unke liye return kar dia mp[string] ye jo root dega
 */
class Solution {
public:
    vector<string> subT;
    unordered_map<string, TreeNode*> mp;
    unordered_map<string, int> freq;
    string helper(TreeNode* root){
        if(!root) return "#";

        string left = helper(root -> left);
        string right = helper(root -> right);

        string ans = left + ',' + right + ',' + to_string(root -> val);
        if(mp.find(ans) == mp.end()){
            mp[ans] = root;
            
        }
        freq[ans]++;
        //cout << ans << endl;
        
        return ans;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        vector<TreeNode*> ans;
        for(auto it : freq){
            if(it.second >= 2){
                ans.push_back(mp[it.first]);
            }
        }
        return ans;
    }
};