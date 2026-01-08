class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        //int temp = pq.top();
        for(int i = 0; i < k; i++){
            //temp = pq.top();
            if(i == k - 1){
                return pq.top();
            }
            pq.pop();
        }
        return 0;
    }
};