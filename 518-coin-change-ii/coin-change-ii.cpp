class Solution {
public:
    // void helper(int amount, vector<int>& coins, int curr, int i, int& ans){
    //     if(i == coins.size() || curr > amount){
    //         return;
    //     }
        
    //     if(curr == amount){
    //         ans++;
    //         return;
    //     }
    //     helper(amount, coins, curr + coins[i], i, ans);
    //     helper(amount, coins, curr, i + 1, ans);
    // }
    int change(int amount, vector<int>& coins) {
        if(amount == 0){
            return 1;
        }
        sort(coins.begin(), coins.end());
        vector<__int128> dp(amount + 1, 0);
        dp[0] = 1;
        int prev = 0;
        for(auto c : coins){
            if(c > amount) break;
            if(prev == c) continue;
            //dp[c] += 1;
            for(int i = c; i <= amount; i++){
                //cout << i << ", " << dp[i] << ", " << i - c << ", " << dp[i - c] << endl;

                dp[i] += dp[i - c];
                if(dp[i] >= INT_MAX) dp[i] = INT_MAX;
            }
            prev = c;
        }
        return (int)dp[amount];
    }
};