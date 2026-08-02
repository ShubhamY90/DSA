class Solution {
public:
    vector<int> parent;
    int find(int u){
        if(parent[u] == u) return u;

        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return false;

        parent[pv] = pu;
        return true;

    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }

        for(auto e : equations){
            if(e[1] == e[2]){
                unite(e[0] - 'a', e[3] - 'a');
            }
        }
        for(auto e : equations){
            if(e[1] != e[2]){
                if(find(e[0] - 'a') == find(e[3] - 'a')) return false;
            }
        }
        return true;
    }
};