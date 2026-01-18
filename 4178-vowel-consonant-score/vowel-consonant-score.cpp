class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int co = 0;
        for(auto c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                v++;
            }
            else if(c >= 'a' && c <= 'z'){
                co++;
            }
        }
        if(co > 0) return v/co;
        return 0;
    }
};