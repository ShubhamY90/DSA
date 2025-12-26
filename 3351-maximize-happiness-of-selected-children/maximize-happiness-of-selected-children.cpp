class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0;

        for(int i = 0; i < k; i++){
            long long temp = (long long)happiness[i] - (long long)i;
            if(temp >= 0){
                ans += temp;
            }
        }
        return ans;
    }
};