class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, int> mp;
        for(auto s : bank){
            mp[s]++;
        }

        queue<string> q;
        q.push(startGene);
        if(mp.count(startGene)) mp[startGene]--;
        q.push("");
        int ans = 0;
        while(!q.empty()){
            string temp = q.front();
            q.pop();
            if(temp == ""){
                ans++;
                if(!q.empty()) q.push("");
                continue;
            }
            if(temp == endGene) return ans;
            for(int i = 0; i < temp.length(); i++){
                char t = temp[i];

                temp[i] = 'A';
                if(mp[temp] > 0){
                    q.push(temp);
                    mp[temp]--;
                }

                temp[i] = 'C'; 
                if(mp[temp] > 0){
                    q.push(temp);
                    mp[temp]--;
                }

                temp[i] = 'G';
                if(mp[temp] > 0){
                    q.push(temp);
                    mp[temp]--;
                }

                temp[i] = 'T';
                if(mp[temp] > 0){
                    q.push(temp);
                    mp[temp]--;
                }
                
                temp[i] = t;
            }
        }
        return -1;
    }
};