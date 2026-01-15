class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));
        vector<bool> s1(str1.length(), false);
        vector<bool> s2(str2.length(), false);
        for(int i = 1; i <= str1.length(); i++){
            for(int j = 1; j <= str2.length(); j++){
                if(str1[i - 1] == str2[j - 1]){
                    
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int n = str1.size();
        int m = str2.size();
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                s1[i - 1] = true;
                s2[j - 1] = true;
                i--;
                j--;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
        i = 0;
        j = 0;
        string ans;
        while(i < str1.length() && j < str2.length()){
            if(s1[i] && s2[j]){
                ans += str1[i];
                i++;
                j++;
                //cout << "1st" << endl;
            }
            else if(s1[i]){
                ans += str2[j];
                j++;
                //cout << "2st" << endl;
            }
            else if(s2[j]){
                ans += str1[i];
                i++;
                //cout << "3st" << endl;
            }
            else{
                ans += str1[i];
                ans += str2[j];
                i++;
                j++;
                //cout << "4st" << endl;
            }
        }
        while(i < str1.length()){
            ans += str1[i];
            i++;
        }
        while(j < str2.length()){
            ans += str2[j];
            j++;
        }
        return ans;
    }
};