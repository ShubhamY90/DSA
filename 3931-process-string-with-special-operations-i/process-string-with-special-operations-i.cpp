class Solution {
public:
    string processStr(string s) {
        string result;
        for(auto c : s){
            if(c >= 'a' && c <= 'z'){
                result += c;
            }
            else if(c == '*'){
                if(result.length() != 0){
                    result.pop_back();
                }
            }
            else if(c == '#'){
                result += result;
            }
            else if(c == '%'){
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};