class Solution {
public:
    bool helper(string &s, string& p, int i, int j){
        if (j == p.length())
            return i == s.length();

        bool first = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        if(j + 1 < p.length() && p[j + 1] == '*'){
            //if x* then i am either skipping x* together or i am using x any no. of times (*) only if the curr chars match otherwise false
            return (helper(s, p, i, j + 2) || (first && helper(s, p, i + 1, j)));
        }
        //normal char i am using 1, 1 of both as they are same
        //if not equal then i just return false as both must match completely
        return first && helper(s, p, i + 1, j + 1);
    }
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
};