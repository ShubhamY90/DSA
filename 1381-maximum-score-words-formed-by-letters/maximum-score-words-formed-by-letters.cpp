class Solution {
public:
    void helper(vector<string>& words, vector<string>& temp, int i, int& ans, unordered_map<char, pair<int,int>>& map){
        if(i == words.size()){
            ans = max(ans, count(temp, map));
            return;
        }
        helper(words, temp, i + 1, ans, map);
        temp.push_back(words[i]);
        helper(words, temp, i + 1, ans, map);
        temp.pop_back();
        return;
    }
    int count(vector<string>& arr, unordered_map<char, pair<int,int>> map){
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[i].length(); j++){
                if(map[arr[i][j]].first > 0){
                    map[arr[i][j]].first--;
                    ans += map[arr[i][j]].second;
                }
                else{
                    return 0;
                }
            }
        }
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, pair<int,int>> map;
        for(int i = 0; i < letters.size(); i++){
            map[letters[i]].first++;
            map[letters[i]].second = score[letters[i] - 'a'];
        }
        int sol = 0;
        vector<string> temp;
        helper(words, temp, 0, sol, map);
        return sol;
    }
};