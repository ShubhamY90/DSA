class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfWays(int n) {

        long long aba = 6;
        long long abc = 6;

        for(int i = 2; i <= n; i++){
            long long newAba = (3 * aba + 2 * abc) % MOD;
            long long newAbc = (2 * aba + 2 * abc) % MOD;
            aba = newAba;
            abc = newAbc;
        }

        return (aba + abc) % MOD;
    }
};