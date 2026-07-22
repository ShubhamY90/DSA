class Solution {
public:
    // int solve(int n) {
    //     if (n <= 1)
    //         return 1;

    //     int ans = 0;

    //     for (int root = 1; root <= n; root++) {
    //         int left = solve(root - 1);
    //         int right = solve(n - root);

    //         ans += left * right;
    //     }

    //     return ans;
    // }
    int dp[20][20];
    int helper(int l, int r) {
        if (l > r) return 1;

        if(dp[l][r] != -1) return dp[l][r];

        int ans = 0;

        for (int root = l; root <= r; root++) {
            ans += helper(l, root - 1) * helper(root + 1, r);
        }

        return dp[l][r] = ans;
    }
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(1, n);
        //return solve(n);
    }
};