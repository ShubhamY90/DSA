class Solution {
public:
    int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        static int dp[201][201][2][201];
        memset(dp, 0, sizeof(dp));

        if(zero > 0) dp[1][0][0][1] = 1;
        if(one > 0) dp[0][1][1][1] = 1;

        for(int i = 0; i <= zero; i++){
            for(int j = 0; j <= one; j++){
                for(int last = 0; last < 2; last++){
                    for(int cons = 1; cons <= limit; cons++){

                        int ways = dp[i][j][last][cons];
                        if(ways == 0) continue;

                        if(i < zero){
                            if(last == 0){
                                if(cons < limit)
                                    dp[i+1][j][0][cons+1] = (dp[i+1][j][0][cons+1] + ways) % MOD;
                            } else {
                                dp[i+1][j][0][1] = (dp[i+1][j][0][1] + ways) % MOD;
                            }
                        }

                        if(j < one){
                            if(last == 1){
                                if(cons < limit)
                                    dp[i][j+1][1][cons+1] = (dp[i][j+1][1][cons+1] + ways) % MOD;
                            } else {
                                dp[i][j+1][1][1] = (dp[i][j+1][1][1] + ways) % MOD;
                            }
                        }

                    }
                }
            }
        }

        long long ans = 0;

        for(int last = 0; last < 2; last++){
            for(int cons = 1; cons <= limit; cons++){
                ans = (ans + dp[zero][one][last][cons]) % MOD;
            }
        }

        return ans;
    }
};