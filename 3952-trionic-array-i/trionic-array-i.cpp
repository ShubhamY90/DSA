class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return false;
        int i = 0;
        for(; i < n - 1; i++){
            if(nums[i + 1] <= nums[i]){
                break;
            }
            
        }
        cout << "1st loop i : " << i << endl;
        if(i == n - 1 || i == 0) return false;
        for(; i < n - 1; i++){
            if(nums[i + 1] >= nums[i]){
                break;
            }
            
        }
        cout << "2nd loop i : " << i << endl;

        if(i == n - 1 || i == 0) return false;
        for(; i < n - 1; i++){
            if(nums[i + 1] <= nums[i]){
                break;
            }
            
        }
        cout << "3rd loop i : " << i << endl;
        if(i != n - 1) return false;
        return true;
    }
};