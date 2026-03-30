class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        vector<int> s1E(26, 0);
        vector<int> s2E(26, 0);
        vector<int> s2O(26, 0);
        vector<int> s1O(26, 0);
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                s1E[s1[i] - 'a'] += 1;
                s2E[s2[i] - 'a'] += 1;
            }
            else{
                s1O[s1[i] - 'a']++;
                s2O[s2[i] - 'a']++;
            }
        }
        if(s1E == s2E && s1O == s2O) return true;
        return false;
    }
};