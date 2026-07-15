class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();

        // CHANGE 1
        ll tSum = accumulate(arr.begin(), arr.end(), 0LL);

        ll minSum = LLONG_MAX;
        ll curr = 0;
        for(int i = 0; i < n; i++){
            if(curr > 0){
                curr = 0;
            }
            curr += arr[i];
            minSum = min(minSum, curr);
        }

        ll maxSum = LLONG_MIN;
        curr = 0;
        for(int i = 0; i < n; i++){
            if(curr < 0){
                curr = 0;
            }
            curr += arr[i];
            maxSum = max(maxSum, curr);
        }

        int maxPre = 0;
        int pre = 0;
        for(int i = 0; i < n; i++){
            pre += arr[i];
            maxPre = max(maxPre, pre);
        }

        int maxSuf = 0;
        int suf = 0;
        for(int i = n - 1; i >= 0; i--){
            suf += arr[i];
            maxSuf = max(maxSuf, suf);
        }

        ll temp2 = LLONG_MIN;

        // CHANGE 2
        if(k >= 2){
            temp2 = maxSuf + maxPre;
            if(tSum > 0){
                temp2 += 1LL * (k - 2) * tSum;
            }
        }

        // CHANGE 3: remove temp1 and (tSum-minSum)
        ll ans = max({0LL, maxSum, temp2});

        // CHANGE 4
        return ans % MOD;
    }
};