class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return false;

        if(size[pv] > size[pu]){
            swap(pu, pv);
        }

        size[pu] += size[pv];
        parent[pv] = pu;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto e : edges){
            if(!dsu.unite(e[0] - 1, e[1] - 1)) return e;
        }
        return {};
    }
};