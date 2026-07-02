/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        vector<Node*> currL;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr == nullptr){
                int n = currL.size();
                //cout << n << endl;
                for(int i = 0; i < n - 1; i++){
                    currL[i] -> next = currL[i + 1];
                }
                currL[n - 1] -> next = nullptr;
                currL.clear();
                if(!q.empty()) q.push(nullptr);
            }
            else{
                currL.push_back(curr);
                if(curr -> left){
                    q.push(curr -> left);
                }
                if(curr -> right){
                    q.push(curr -> right);
                }
            }
        }
        return root;
    }
};