class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //using dijkstra
        int r = heights.size();
        int c = heights[0].size();

        if(r == 1 && c == 1){
            return 0;
        }
        
        vector<vector<int>> diff(r, vector<int> (c, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int eff = pq.top().first;
            pair pos = pq.top().second;
            int tr = pos.first;
            int tc= pos.second;
            pq.pop();
            vector<int> dr = {1, -1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};
            for(int i = 0; i < 4; i++){
                int nr = tr + dr[i];
                int nc = tc + dc[i];
                if(nr >= 0 && nr < r && nc >= 0 && nc < c){
                    int neff = max(abs(heights[tr][tc] - heights[nr][nc]), eff);
                    if(neff < diff[nr][nc]){
                        diff[nr][nc] = neff;
                        pq.push({neff, {nr, nc}});
                    }
                }
            }
        }
        return diff[r - 1][c - 1];
    }
};