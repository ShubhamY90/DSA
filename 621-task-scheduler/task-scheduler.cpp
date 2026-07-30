class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(auto c : tasks){
            freq[c]++;
        }
        
        priority_queue<int> pq;
        for(auto it : freq){
            pq.push(it.second);
        }
        int ans = 0;

        while(!pq.empty()){
            vector<int> temp;
            for(int i = 0; i <= n; i++){
                if(!pq.empty()){
                    int curr = pq.top();
                    curr--;
                    temp.push_back(curr);
                    pq.pop();
                }
            }
            

            for(auto it : temp){
                if(it > 0) pq.push(it);
            }

            if(pq.size()>0){
                ans+=n+1;
            }
            else{
                ans+=temp.size();
            }
        }
        return ans;
    }
};