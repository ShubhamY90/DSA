/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string to_str(int n){
        string s = to_string(n);
        while(s.length() < 4){
            s = '0' + s;
        }
        return s;
    }

    // Encodes a tree to a single string.
    string tree;
    string serialize(TreeNode* root) {
        if(!root) return "";

        tree += to_str(root -> val);
        serialize(root -> left);
        serialize(root -> right);
        
        return tree;
    }

    // Decodes your encoded data to tree.
    //pass i by reference such that preorder only moves forward
    TreeNode* helper(vector<int>& preorder, int& i, int bound){
        if(i == preorder.size() || preorder[i] > bound){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        //root ke left mei rkhunga preorder[i] se kam saare bache huye
        // preorder[i] nhi likh sakta root->val ki jagah kyuki i badha dia
        root -> left = helper(preorder, i, root -> val);

        //root ke right mei jo current bound chal rha tha usse hi kam bas
        root -> right = helper(preorder, i, bound);

        return root;
    }

    TreeNode* deserialize(string data) {
        cout << data << endl;
        int n = data.length();
        vector<int> preorder(n/4);
        for(int i = 0; i < n - 3; i += 4){
            preorder[i/4] = stoi(data.substr(i, 4));
        }
        for(int i = 0; i < preorder.size(); i++){
            cout << preorder[i] << " ";
        }
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;