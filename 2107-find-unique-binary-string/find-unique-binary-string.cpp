class Solution {
public:
    long long dec(string s){
        long long n = 0;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.length(); i++){
            n += (s[i] - '0') * pow(2, i);
        }
        return n;
    }
    string binary(long long n, int k){
        string s;
        while(n){
            if(n % 2 == 0){
                s += '0';
            }
            else{
                s += '1';
            }
            n /= 2;
        }
        reverse(s.begin(), s.end());
        int curr = s.length();
        for(int i = 0; i < k - curr; i++){
            s.insert(s.begin(), '0');
        }
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        // string test1 = "001";
        // cout << dec(test1) << endl;
        // cout << binary(dec(test1), n) << endl;
        // return "11";
        unordered_map<long long, int> map;
        for(auto s : nums){
            long long temp = dec(s);
            map[temp]++;
        }
        for(long long i = 0; i < pow(2, n); i++){
            if(map.count(i) == 0){
                return binary(i, n);
            }
        }
        return "-1";
    }
};