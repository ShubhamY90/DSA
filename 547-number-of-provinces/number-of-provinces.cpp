class DSU {
public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(parent[u] == u) return u;
        
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv){
            return false;
        }

        parent[pu] = pv;
        return true;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1) dsu.unite(i, j);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(i == dsu.find(i)) ans++;
        }
        return ans;
    }
};