class Solution {
public:
    vector<int> search(vector<int>& nums){
        int n = nums.size();
        int i = 0;
        for(; i < n; i++){
            if(nums[i] == 0) break;
        }
        bool f1 = true;
        for(int j = i; j < n + i - 1; j++){
            if(nums[j%n] > nums[(j + 1)%n]){
                f1 = false;
            }
        }
        bool f2 = true;

        for (int k = 0; k < n - 1; k++) {
            if (nums[(i - k + n) % n] > nums[(i - k - 1 + n) % n]) {
                f2 = false;
                break;
            }
        }
        if(f1) return {i, 1};
        if(f2) return {i, 2};
        return {-1, -1};
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        auto pivot = search(nums);
        if(pivot[0] == -1) return -1;
        if(pivot[1] == 1){
            //cout << 1 << " pivot: " << pivot[0] << endl;
            return min(pivot[0], 2 + n - pivot[0]);
        }
        else{
            //cout << 2 << " pivot: " << pivot[0] << endl;
            return min(1 + (n - pivot[0] - 1), (2 + pivot[0]));
        }
        return -1;
    }
};