class Solution {
public:
    int maxDepth(string s) {
        int c = 0;
        int ans = INT_MIN;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                c++;
            }
            else if(s[i] == ')'){
                c--;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};