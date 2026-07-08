class Solution {
public:
    int MOD = 1e9 + 7;
    long long helper(string s){
        long long n = 0;
        for(char c : s){
            int temp = (c - '0');
            n = n*10 + (long long)temp;
            n %= MOD;
        }
        return n;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {    
        int n = s.length();
        string s1;
        vector<int> ind;
        //ind.push_back(0);
        vector<int> pref(n + 1, 0);
        unordered_map<int, int> mp;
        int k = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '0'){
                ind.push_back(i);
                s1 += s[i];
                
                mp[i] = k;
                //cout << "mp[" << i << "]: " << mp[i] << " k: " << k << endl;
                k++;
            }

            pref[i + 1] = pref[i] + (s[i] - '0');
        }

        vector<long long> pow(s1.length() + 1);
        pow[0] = 1;

        for (int i = 1; i <= s1.length(); i++) {
            pow[i] = (pow[i - 1] * 10) % MOD;
        }

        vector<long long> preString(s1.length() + 1, 0);

        for (int i = 0; i < s1.length(); i++) {
            preString[i + 1] = (preString[i] * 10 + (s1[i] - '0')) % MOD;
        }
        
        vector<int> ans;

        for(auto q : queries){
            //finds first index >= q[0];
            auto it1 = lower_bound(ind.begin(), ind.end(), q[0]);
            if(it1 == ind.end()){
                ans.push_back(0);
                continue;
            }
            int i = *it1;
            //finds first element <= q[1];
            auto it = upper_bound(ind.begin(), ind.end(), q[1]);
            if (it == ind.begin()) {
                ans.push_back(0);
                continue;
            }
            --it;
            int j = *it;

            
            //cout << "i: " << i << " j: " << j << endl;
            i = mp[i];
            j = mp[j];
            //cout << mp[i] << " " << mp[j] << endl;

            long long temp = (preString[j + 1] - pow[j - i + 1]*preString[i]%MOD + MOD)%MOD;
            


            // if(temp.length() == 0){
            //     ans.push_back(0);
            //     continue;
            // }
            //cout << "x: " << temp << endl;
            //stoi is for int instead using stoll for long long
            long long t1 = temp;
            //t1 %= MOD;
            long long t2 = pref[q[1] + 1] - pref[q[0]];
            //t2 %= MOD;
            //cout << "sum: " << t2 << endl;
            long long t3 = t1*t2;
            t3 %= MOD;
            ans.push_back((int)t3);
        }
        return ans;
    }
};