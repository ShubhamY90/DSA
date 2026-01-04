class Solution {
public:
    int helper(int n){
        int i = 1;
        int ans = 0;
        set<int> sol;
        for(;i*i <= n ; i++){
            if(n%i == 0){
                sol.insert(i);
                sol.insert(n/i);
                //cout << "pushed : " << i << " and " << n/i << " for " << n << endl;
            }
        }
        //cout << "last i " << i << endl;
        if(sol.size() == 4){
            for(auto it : sol){
                ans += it;
            }
            return ans;
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += helper(nums[i]);
        }
        return ans;
    }
};