class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return nums;
        }
        else if(n == 2){
            if(nums[0] == nums[1]){
                return {nums[0]};
            }
            else{
                return nums;
            }
        }
        int t = n/3;
        sort(nums.begin(), nums.end());
        int c = 1;
        vector<int> ans;
        
        for(int i = 1; i < n; i++){
            if(nums[i - 1] == nums[i]){
                c++; 
            }
            else{
                c = 1;
            }
            cout << c << endl;
            if(c > t){
                ans.push_back(nums[i - 1]);
                while(i < n && nums[i - 1] == nums[i]){
                    i++;
                }
                c = 1;
            }
        }
        return ans;
    }
};