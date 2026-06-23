class DSU{
public:
    vector<int> sz, parent;
    DSU(int n){
        sz.resize(n + 1, -1);
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
    }

    int find(int n){
        if(parent[n] == n) return n;

        return parent[n] = find(parent[n]);
    }

    bool unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return false;

        if(sz[pb] > sz[pa]){
            parent[pa] = pb;
            sz[pb]++;
        }
        else{
            parent[pb] = pa;
            sz[pa]++;
        }
        return true;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size() + 1;
        DSU dsu(26);
        for(auto& e : equations){
            int i = e[0] - 'a';
            int j = e[3] - 'a';
            string cond = e.substr(1, 2);
            if(cond == "=="){
                dsu.unite(i, j);
            }
        }
        for(auto& e : equations){
            int i = e[0] - 'a';
            int j = e[3] - 'a';
            string cond = e.substr(1, 2);
            if(cond == "!="){
                if(dsu.find(i) == dsu.find(j)) return false;
            }
        }
        return true;
    }
};