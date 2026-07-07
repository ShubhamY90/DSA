class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> mp;
        for(auto s : deadends){
            mp[s]++;
        }
        if(mp["0000"] > 0) return -1;
        queue<string> q;
        q.push("0000");
        q.push("");
        int ans = 0;
        unordered_map<string, bool> vis;
        vis["0000"] = true;
        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr == ""){
                ans++;
                if(!q.empty()) q.push("");
            }

            if(curr == target) return ans;

            for(int i = 0; i < curr.length(); i++){
                char t = curr[i];
                int currNum = curr[i] - '0';
                int prev = 0;
                int next = 0;
                if(currNum == 0){
                    prev = 9;
                }
                else{
                    prev = currNum - 1;
                }
                if(currNum == 9){
                    next = 0;
                }
                else{
                    next = currNum + 1;
                }
                curr[i] = prev + '0';
                if(mp.find(curr) == mp.end() && vis.find(curr) == vis.end()){
                    q.push(curr);
                    vis[curr] = true;
                }
                curr[i] = next + '0';
                if(mp.find(curr) == mp.end() && vis.find(curr) == vis.end()){
                    q.push(curr);
                    vis[curr] = true;
                }
                curr[i] = t;
            }
        }
        return -1;
    }
};