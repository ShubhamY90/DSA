class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for(auto c : s){
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it : freq){
            pq.push({it.second, it.first});
        }
        string ans;
        while(!pq.empty()){
            vector<pair<int, char>> temp;
            for(int i = 0; i < 2; i++){
                if(!pq.empty()){
                    auto [cF, curr] = pq.top();
                    if(ans.size() > 0 && ans.back() == curr) return "";
                    ans += curr;
                    cF--;
                    if(cF > 0) temp.push_back({cF, curr});
                    pq.pop();
                }
                
            }

            for(auto it : temp){
                pq.push(it);
            }
            temp.clear();
        }
        return ans;
    }
};