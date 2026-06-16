class Solution {
public:
    int helper(int n, vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
        if(j - i == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        // for(auto it : cuts){
        //     int temp = 0;
        //     int k = it.first;
        //     if(k > i && k < j){
        //         temp = cuts[j] - cuts[i] + helper(n, cuts, i, k, dp) + helper(n, cuts, k, j, dp);
        //         ans = min(temp, ans);
        //     }
        // }
        for(int k = i + 1; k < j; k++){
            int temp = 0;
            //if(cuts.find(k) != cuts.end()){
            temp = cuts[j] - cuts[i] + helper(n, cuts, i, k, dp) + helper(n, cuts, k, j, dp);
            ans = min(temp, ans);
            //}
        }
        if(ans == INT_MAX) return dp[i][j] = 0;
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        //unordered_map<int, bool> cut;
        // for(int i = 0; i < cuts.size(); i++){
        //     cut[cuts[i]] = true;
        // }
        vector<vector<int>> dp(cuts.size() + 3, vector<int>(cuts.size() + 3, -1));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return helper(n, cuts, 0, cuts.size() - 1, dp);

        //for(int i = 0; i <)
    }
};