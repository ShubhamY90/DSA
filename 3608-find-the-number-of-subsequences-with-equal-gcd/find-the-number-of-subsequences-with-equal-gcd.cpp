class Solution {
public:
    long long dp[201][201][201];
    typedef long long ll;
    int MOD = 1e9 + 7;
    int helper(vector<int>& nums, int i, int g1, int g2){
        if(i == (int)nums.size()){
            if(g1 != 0 && g1 == g2){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][g1][g2] != -1) return (int)(dp[i][g1][g2]%MOD);
        int curr = nums[i];

        int ng1 = gcd(g1, curr);
        int ng2 = gcd(g2, curr);
        return dp[i][g1][g2] = ((ll)(helper(nums, i + 1, g1, g2)%MOD) + (ll)(helper(nums, i + 1, ng1, g2)%MOD) + (ll)(helper(nums, i + 1, g1, ng2)%MOD))%MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, 0, 0);
    }
};