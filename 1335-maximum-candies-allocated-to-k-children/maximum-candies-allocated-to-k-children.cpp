class Solution {
public:
    bool can(vector<int>& candies, long long k, int c){
        int n = candies.size();
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += (candies[i]/c);
        }
        return (ans >= k);
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;
        int r = 10000000;
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(can(candies, k, mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};