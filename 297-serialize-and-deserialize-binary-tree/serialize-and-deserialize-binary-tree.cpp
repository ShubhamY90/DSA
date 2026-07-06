/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 1.created two functions for converting dec to binary and vice versa in exactly 11 bits for every number as limit is -1000 to 1000
 2. so doing biasing offset 0 to 2000 so 2^11
 3. now calculated postorder and inorder
 4. putting these in strings inorder + postorder
 5. and passed this in buildtree
 6. build tree is taken from question 106 
 7. call on root then right and left
 8. returned the built tree

  above doesnt work as the values can be duplicate here 

  doing bfs stoding null values as # and then building again from bfs
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "#";

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                ans += "#,";
                continue;
            }

            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }

    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;

        vector<string> vals;
        string cur;

        for (char c : data) {
            if (c == ',') {
                vals.push_back(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }

        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (vals[i] != "#") {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;

            if (vals[i] != "#") {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));