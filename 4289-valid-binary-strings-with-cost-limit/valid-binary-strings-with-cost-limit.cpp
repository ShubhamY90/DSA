class Solution {
public:
    vector<string> ans;
    void helper(int n, int k, int i, int c, string temp, bool prev){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        if(!prev && c + i <= k){
            helper(n, k, i + 1, c + i, temp + '1', true);
        }
        helper(n, k, i + 1, c, temp + '0', false);
        return;
    }
    vector<string> generateValidStrings(int n, int k) {
        string temp;
        helper(n, k, 0, 0, temp, false);
        return ans;
    }
};