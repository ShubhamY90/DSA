class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                for(int j = i; j < s.length(); j++){
                    if(s[j] == '1') return false;
                }
                break;
            }
        }
        return true;
    }
};