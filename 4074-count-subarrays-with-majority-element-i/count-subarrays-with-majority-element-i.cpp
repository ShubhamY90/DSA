class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        freq[0] = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == target) freq[i + 1] = freq[i] + 1;
            else freq[i + 1] = freq[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            //vector<int> temp;
            for(int j = i; j < n; j++){
                //temp.push_back(nums[j]);
                //cout << "freq[j + 1]: " << freq[j + 1] << ", freq[i]: " << freq[i] << ", j: " << j << ", i: " << i << endl;
                if(freq[j + 1] - freq[i] > (j - i + 1)/2){
                    //cout << "freq[j + 1]: " << freq[j + 1] << ", freq[i]: " << freq[i] << "j + 1: " << j + 1 << ", i: " << i << endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};