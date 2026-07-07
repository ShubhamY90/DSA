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
    vector<string> subT;
    unordered_map<string, TreeNode*> mp;
    string helper(TreeNode* root){
        if(!root) return "#";

        string left = helper(root -> left);
        string right = helper(root -> right);

        string ans = left + ',' + right + ',' + to_string(root -> val);
        if(mp.find(ans) == mp.end()){
            mp[ans] = root;
            
        }
        subT.push_back(ans);
        //cout << ans << endl;
        
        return ans;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        int n = subT.size();
        vector<TreeNode*> ans;
        unordered_map<string, bool> visited;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(subT[i] == subT[j] && visited.find(subT[i]) == visited.end()){
                    visited[subT[i]] = true;
                    ans.push_back(mp[subT[i]]);
                }
            }
        }
        return ans;
    }
};