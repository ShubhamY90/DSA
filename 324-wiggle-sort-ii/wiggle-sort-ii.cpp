class Solution {
public:
/*
    1st iteration   TC : O(nlog(n));
                    SC : O(n);

*/
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> first(nums.begin(), nums.begin() + (n + 1) / 2);
        vector<int> second(nums.begin() + (n + 1) / 2, nums.end());

        int i = first.size() - 1;
        int j = second.size() - 1;
        int k = 0;

        while (k < n) {
            if (k % 2 == 0) {
                nums[k] = first[i];
                i--;
            } else {
                nums[k] = second[j];
                j--;
            }
            k++;
        }
        return;
    }
};