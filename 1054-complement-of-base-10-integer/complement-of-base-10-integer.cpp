class Solution {
public:
    void comp(string& s){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        return;
    }
    string bin(int n){
        string ans;
        while(n){
            if(n % 2 == 0){
                ans += '0';
            }
            else{
                ans += '1';
            }
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    long long dec(string s){
        long long num = 0;
        int n = s.length();
        for(int i = s.length() - 1; i >= 0; i--){
            num += (s[i] - '0') * pow(2, n - i - 1);
        }
        return num;
    }
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        string temp = bin(n);
        cout << n << " " << temp << endl;
        comp(temp);
        cout << dec(temp) << " " << temp << endl; 
        return (int)dec(temp);
    }
};