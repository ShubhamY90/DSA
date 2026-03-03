class Solution {
public:
    string invert(string s){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') s[i] = '1';
            else{
                s[i] = '0';
            }
        }
        return s;
    }
    void helper(string& s, int n, int i){
        if(i == n) return;
        string temp1 = invert(s);
        reverse(temp1.begin(), temp1.end());
        s = s + '1' + temp1;
        helper(s, n, i + 1); 
    }
    char findKthBit(int n, int k) {
        string s = "0";
        helper(s, n, 0);
        //cout << s << endl;
        
        return s[k - 1];
    }
};