class DSU{
public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n + 1);
        rank.resize(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            rank[i] = 27 - i;
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

        if(rank[pa] < rank[pb]){
            swap(pa, pb);
        }
        parent[pb] = pa;
        return true;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        DSU dsu(26);
        for(int i = 0; i < n; i++){
            dsu.unite(s1[i] - 'a' + 1, s2[i] - 'a' + 1);
        }
        string ans;
        for(auto c : baseStr){
            ans += 'a' + dsu.find(c - 'a' + 1) - 1;
        }
        return ans;
    }
};