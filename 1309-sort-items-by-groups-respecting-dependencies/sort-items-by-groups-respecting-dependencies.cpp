class Solution {
public:
    vector<int> order(vector<vector<int>>& graph, vector<int>& in){
        int n = graph.size();
        queue<int> q;
        vector<int> o;
        for(int i = 0; i < n; i++){
            if(in[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int temp1 = q.front();
            q.pop();
            o.push_back(temp1);
            for(int j = 0; j < graph[temp1].size(); j++){
                int temp2 = graph[temp1][j];
                in[temp2]--;
                if(in[temp2] == 0) q.push(temp2);
            }
        }
        if(o.size() != n) return {};
        return o;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int gU = *max_element(group.begin(), group.end()) + 1;
        for(int i = 0; i < n; i++){
            if(group[i] == -1){
                group[i] = gU;
                gU++;
            }
        }
        // topo on groups to know which group to process first
        vector<vector<int>> graph1(gU);
        vector<int> in1(gU, 0);
        // topo on items according to group order
        vector<vector<int>> graph(n);
        vector<int> in(n, 0);

        for(int i = 0; i < n; i++){
            for(auto j : beforeItems[i]){
                if(group[j] != group[i]){
                    graph1[group[j]].push_back(group[i]);
                    in1[group[i]]++;
                }

                graph[j].push_back(i);
                in[i]++;
            }
        }

        //order of group to follow
        vector<int> o1 = order(graph1, in1);

        //order of elements
        vector<int> temp = order(graph, in);

        //ab order of elements le lenge group ke order ke hisaab se 
        // pahle o1[0] group ke saare elements order mei fir aage ke
        if(o1.size() < 1 || temp.size() < 1) return {};
        unordered_map<int, vector<int>> bucket;
        for(int i = 0; i < temp.size(); i++){
            bucket[group[temp[i]]].push_back(temp[i]);
        }
        vector<int> ans;
        for(int i = 0; i < gU; i++){
            for(auto j : bucket[o1[i]]){
                ans.push_back(j);
            }
        }
        return ans;
    }
};