class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n + 1, -1);
        vector<int> dist2(n + 1, -1);
        // vector<vector<int>> adj(n + 1);
        // for(int i = 0; i < n; i++){
        //     adj[i].push_back(edges[i]);
        // }

        //i can use queue as well doing bfs but not neccessary for this 
        // directly navigating as every node has only one outgoing edge

        int d1 = 0;
        int curr1 = node1;
        while(curr1 != -1 && dist1[curr1] == -1){
            dist1[curr1] = d1;
            curr1 = edges[curr1];
            d1++;
        }
        int d2 = 0;
        int curr2 = node2;
        while(curr2 != -1 && dist2[curr2] == -1){
            dist2[curr2] = d2;
            curr2 = edges[curr2];
            d2++;
        }
        int dis = INT_MAX;
        int ans = INT_MAX;
        for(int i = 0; i <= n; i++){
            if(dist1[i] != -1 && dist2[i] != -1){
                if(max(dist1[i], dist2[i]) < dis){
                    ans = i;
                    dis = max(dist1[i], dist2[i]);
                }

                else if(max(dist1[i], dist2[i]) == dis) 
                    ans = min(ans, i);
            }
        }
        if(dis == INT_MAX) return -1;
        return ans;
    }
};