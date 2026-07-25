class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> adj = {
        {4, 6},      // 0
        {6, 8},      // 1
        {7, 9},      // 2
        {4, 8},      // 3
        {0, 3, 9},   // 4
        {},          // 5
        {0, 1, 7},   // 6
        {2, 6},      // 7
        {1, 3},      // 8
        {2, 4}       // 9
    };
    int dp[5001][11];
    int helper(int n, int i, int digit){
        if(i == n){
            return 1;
        }
        if(dp[i][digit] != -1) return dp[i][digit];
        int ans = 0;
        for(auto next : adj[digit]){
            ans = (ans + (helper(n, i + 1, next))%MOD)%MOD;
        }
        return dp[i][digit] = ans;
    }
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        for(int i = 0; i < 10; i++){
            ans += helper(n, 1, i);
        }
        ans %= MOD;
        return (int)ans;
    }
};