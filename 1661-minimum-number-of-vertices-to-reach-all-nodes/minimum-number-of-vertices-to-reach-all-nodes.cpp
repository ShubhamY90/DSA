class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inD(n, 0);
        for(auto e : edges){
            inD[e[1]]++;
        }
        vector<int> ans;
        for(int i = 0; i < inD.size(); i++){
            if(inD[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};