class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        if(num1 == "0" || num2 == "0") return "0";
        int carry = 0;
        string ans;
        vector<string> calc(n1);
        for(int i = n1 - 1; i >= 0; i--){
            for(int k = n1 - i - 1; k > 0; k--){
                calc[i] += '0';
            }

            int t1 = num1[i] - '0';
            cout << t1 << ": ";
            for(int j = n2 - 1; j >= 0; j--){

                int t2 = num2[j] - '0';
                cout << t2 << ", ";
                int mul = t1*t2 + carry;
                carry = mul/10;
                mul = mul%10;
                cout << "mul: " << mul << ", carry: " << carry << endl;
                calc[i] = to_string(mul) + calc[i];
            }
            cout << endl;
            calc[i] = to_string(carry) + calc[i];
            carry = 0;
        }
        reverse(calc.begin(), calc.end());
        int mxS = INT_MIN;
        for(int i = 0; i < n1; i++){
            cout << calc[i] << endl;
            mxS = max(mxS, (int)calc[i].length());
        }
        cout << mxS << endl;
        
        for(int i = 0; i < n1; i++){
            int temp = (int)calc[i].length();
            for(int j = 0; j < (mxS - temp); j++){
                calc[i] = '0' + calc[i];
            }
        }
        carry = 0;
        //string ans;
        for(int i = mxS - 1; i >= 0; i--){
            int t1 = 0;
            for(int j = 0; j < n1; j++){
                t1 += calc[j][i] - '0';
            }
            t1 += carry;
            carry = t1/10;
            t1 = t1%10;
            ans = to_string(t1) + ans;
        }
        if(carry > 0) ans = to_string(carry) + ans;
        while(ans[0] == '0'){
            ans.erase(0, 1);
        }
        return ans;
    }
};