class DSU{
    vector<int> size, parent;
public:
    DSU(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unionBS(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(size[pv] > size[pu]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int s(int x){
        return size[find(x)];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n*n);
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    vector<int> dx = {0, 0, -1, 1};
                    vector<int> dy = {1, -1, 0, 0};
                    int id1 = i*n + j;
                    for(int k = 0; k < 4; k++){
                        int nx = dx[k] + i;
                        int ny = j + dy[k];
                        if(nx >= n || ny >= n || nx < 0 || ny < 0 || grid[nx][ny] == 0) continue;
                        int id2 = nx*n + ny;
                        
                        dsu.unionBS(id1, id2);
                        //ans = max(ans, dsu.s(dsu.find(id1)));
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    int temp = 1;
                    vector<int> dx = {0, 0, -1, 1};
                    vector<int> dy = {1, -1, 0, 0};
                    unordered_set<int> seen;

                    for(int k = 0; k < 4; k++){
                        int nx = dx[k] + i;
                        int ny = j + dy[k];
                        if(nx >= n || ny >= n || nx < 0 || ny < 0 || grid[nx][ny] == 0) continue;

                        int x = dsu.find(nx*n + ny);
                        if(seen.find(x) == seen.end()){
                            temp += dsu.s(x);
                            seen.insert(x);
                        }
                    }
                    ans = max(ans, temp);
                }
            }
        }
        for(int i = 0; i < n*n; i++){
            ans = max(ans, dsu.s(i));
        }
        return ans;
    }
};