class DSU {
public:
    vector<int> parent, sz;
    DSU(int n){
        sz.resize(n + 1);
        parent.resize(n + 1, 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return false;

        if(sz[pa] < sz[pb]){
            swap(pa, pb);
        }
        parent[pb] = pa;
        sz[pa]++;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto e : edges){
            if(!dsu.unite(e[0], e[1])){
                return e;
            }
        }
        return {};
    }
};