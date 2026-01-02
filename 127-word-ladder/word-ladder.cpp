class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<tuple<string, int>> q;
        q.push({beginWord, 1});
        int n = wordList.size();
        vector<bool> visited(n, false);
        while(!q.empty()){
            auto [curr, level] = q.front();
            q.pop();
            if(curr == endWord){
                return level;
            }
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    int diff = 0;
                    for(int j = 0; j < wordList[i].length(); j++){
                        if(wordList[i][j] != curr[j]){
                            diff++;
                        }
                    }
                    if(diff == 1){
                        q.push({wordList[i], level + 1});
                        visited[i] = true;
                    }
                }
            }
        }
        return 0;
    }
};