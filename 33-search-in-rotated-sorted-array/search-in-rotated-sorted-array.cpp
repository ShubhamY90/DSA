class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while(i < j){
            int m = i + (j - i)/2;
            if(nums[m] > nums[n - 1]) i = m + 1;
            else j = m;
        }

        int r = i;
        cout << r << endl;
        i = 0, j = n - 1;
        while(i <= j){
            int m = i + (j - i)/2;
            int t = (m + r) % n;
            if(nums[t] == target) return t;
            else if(nums[t] < target) i = m + 1;
            else j = m - 1;
        }
        return -1;
    }
};