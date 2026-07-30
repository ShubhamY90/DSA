class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kt;
    KthLargest(int k, vector<int>& nums) {
        kt = k;
        for(auto i : nums){
            if(pq.empty()){
                pq.push(i);
            }
            else if(pq.size() >= k){
                if(pq.top() < i){
                    pq.push(i);
                    pq.pop();
                }
            }
            else{
                pq.push(i);
            }
        }
    }
    
    int add(int i) {
        int k = kt;
        if(pq.empty()){
            pq.push(i);
        }
        else if(pq.size() >= k){
            if(pq.top() < i){
                pq.push(i);
                pq.pop();
            }
        }
        else{
            pq.push(i);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */