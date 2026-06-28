class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        bool unite(int x, int y) {
            x = find(x);
            y = find(y);

            if (x == y) return false;

            if (rank[x] < rank[y])
                swap(x, y);

            parent[y] = x;

            if (rank[x] == rank[y])
                rank[x]++;

            return true;
        }
    };

    int kruskal(int n, vector<vector<int>>& edges, int skip, int force) {
        DSU dsu(n);

        int weight = 0;
        int cnt = 0;

        if (force != -1) {
            dsu.unite(edges[force][0], edges[force][1]);
            weight += edges[force][2];
            cnt++;
        }

        for (int i = 0; i < edges.size(); i++) {

            if (i == skip) continue;

            if (dsu.unite(edges[i][0], edges[i][1])) {
                weight += edges[i][2];
                cnt++;
            }
        }

        if (cnt != n - 1)
            return INT_MAX;

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        int m = edges.size();

        vector<vector<int>> e;

        for (int i = 0; i < m; i++) {
            e.push_back({
                edges[i][0],
                edges[i][1],
                edges[i][2],
                i
            });
        }

        sort(e.begin(), e.end(),
            [](auto &a, auto &b) {
                return a[2] < b[2];
            });

        int mstWeight = kruskal(n, e, -1, -1);

        vector<vector<int>> ans(2);

        for (int i = 0; i < m; i++) {

            if (kruskal(n, e, i, -1) > mstWeight) {
                ans[0].push_back(e[i][3]);
            }
            else if (kruskal(n, e, -1, i) == mstWeight) {
                ans[1].push_back(e[i][3]);
            }
        }

        return ans;
    }
};