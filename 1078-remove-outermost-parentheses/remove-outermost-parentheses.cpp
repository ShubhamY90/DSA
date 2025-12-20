class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        for(int i =0; i < s.length(); i++){
            if(s[i] == '('){
                cout << "i: " << i << " ,";
                int count = 1;
                int e = i + 1;
                while(count != 0 && e < s.length()){
                    if(s[e] == ')'){
                        count--;
                    }
                    else{
                        count++;
                    }
                    e++;
                }
                ans += s.substr(i + 1, e - i - 2);
                i = e - 1;
                cout << "e: " << e - 1 << endl;
            }

        }
        return ans;
    }
};