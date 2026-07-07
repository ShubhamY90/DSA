//pahle topo sort
// fir topo sort ke hisaab se agar ek node x ko a,b,c chaiye 
// to max(a,b,c) hoga x ko shuru karne se pahle
// ab x ka time update kar denge time[x] + time[max(a,b,c)]
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> in(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        vector<vector<int>> adj1(n + 1);
        for(auto r : relations){
            in[r[1]]++;
            adj[r[0]].push_back(r[1]);
            adj1[r[1]].push_back(r[0]);
        }
        
        queue<int> q;
        vector<int> order;
        for(int i = 1; i <= n; i++){
            if(in[i] == 0){
                q.push(i);
                order.push_back(i);
            }
        }        
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto a : adj[curr]){
                in[a]--;
                if(in[a] == 0){
                    q.push(a);
                    order.push_back(a);
                }
            }
        }
        vector<int> ans(n + 1, 0);
        for(int i = 0; i < n; i++){
            int temp = 0;
            for(auto a : adj1[order[i]]){
                temp = max({temp, time[a - 1], ans[a]});
            }
            //cout << "node: " << order[i] << " time: " << temp << endl;
            ans[order[i]] = time[order[i] - 1] + temp;
            //time[order[i]] = ans[order[i]];
        }
        // cout << "time for each: ";
        // for(int i = 1; i <= n; i++){
        //     cout << ans[i] << " ";
        // }
        return *max_element(ans.begin(), ans.end());
    }
};