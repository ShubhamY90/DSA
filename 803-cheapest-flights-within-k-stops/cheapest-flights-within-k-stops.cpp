class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //code from 1631 (was as an undirected graph here as directed)
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < flights.size(); i++){
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
            //graph[i].push_back(flights[i][2]);
        }
        //k + 2 because the stops start from 1 and we need k + 1 for a city therefore size is k + 2 to get the k + 1 index
        vector<vector<int>> dist(n, vector<int> (k + 2, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.push({0, src, 0});
        while(!pq.empty()){
            auto [cost, city, stop] = pq.top();
            pq.pop();
            if(city == dst) return cost;
            if(stop > k) continue;
            for(auto[c, p] : graph[city]){
                int nc = p + cost;
                if(nc < dist[c][stop + 1]){
                    dist[c][stop + 1] = nc;
                    pq.push({nc, c, stop + 1});
                }
            }
        }
        return -1;
    }
};