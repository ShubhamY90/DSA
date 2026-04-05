class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0;
        int d = 0;
        int r = 0;
        int l = 0;
        for(auto c : moves){
            if(c == 'U') u++;
            else if(c == 'D') d++;
            if(c == 'L') l++;
            else if(c == 'R') r++;
        }
        if(u == d && l == r) return true;
        return false;
    }
};