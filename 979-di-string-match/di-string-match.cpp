class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i = 0;
        int n = s.length();
        int j = n;
        vector<int> ans(n + 1);
        for(int k = 0; k < n; k++){
            if(s[k] == 'I'){
                ans[k] = i++;
            }
            else{
                ans[k] = j--;
            }
        }
        if(s[n - 1] == 'I') ans[n] = i;
        else ans[n] = j;
        return ans;
    }
};