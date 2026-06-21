class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<bool, bool>> t(n + 1);
        for(auto p : trust){
            t[p[0]].first = true;
        }
        vector<int> pos;
        for(int i = 1; i < n + 1; i++){
            if(!t[i].first) pos.push_back(i);
        }
        if(pos.size() != 1){
            //cout << "pos.size() != -1" << endl;
            return -1;
        }
        //cout << pos[0] << endl;
        for(auto p : trust){
            if(p[1] == pos[0]){
                t[p[0]].second = true;
            }
        }
        for(int i = 1; i < n + 1; i++){
            if(i == pos[0]) continue;
            if(!t[i].second){
                //cout << i <<  " -> !it[i].second" << endl;
                return -1;
            }
        }
        return pos[0];
    }
};