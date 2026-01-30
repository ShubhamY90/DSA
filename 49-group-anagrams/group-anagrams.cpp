class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(strs[i]);
        }
        for(auto m : map){
            vector<string> temp;
            for(int i = 0; i < m.second.size(); i++){
                temp.push_back(m.second[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};