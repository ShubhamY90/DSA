class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.length();
        unordered_map<string, bool> m;
        for(int i = 0; i < n; i++){
            string temp;
            for(int j = i; j < n; j++){
                temp += word[j];
                m[temp] = true;
            }
        }
        int ans = 0;
        for(auto p : patterns){
            if(m[p]) ans++;
        }
        return ans;
    }
};