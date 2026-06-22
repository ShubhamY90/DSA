class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        for(char c : text){
            if(c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') m[c]++;
        }
        if(m.size() != 5) return 0;
        int ans = INT_MAX;
        for(auto it : m){
            if(it.first == 'b') ans = min(ans, it.second);
            if(it.first == 'a') ans = min(ans, it.second);
            if(it.first == 'l') ans = min(ans, it.second/2);
            if(it.first == 'o') ans = min(ans, it.second/2);
            if(it.first == 'n') ans = min(ans, it.second);
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};