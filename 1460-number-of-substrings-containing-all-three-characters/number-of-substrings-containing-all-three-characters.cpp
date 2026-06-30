class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int req = 3;
        int found = 0;
        unordered_map<char, int> mf;
        // for(int i = 0; i < n; i++){
        //     if(mr.find(s[i]) == mr.end()){
        //         req++;
        //     }
        //     mr[s[i]]++;
        // }
        int ans = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(mf.find(s[i]) == mf.end()){
                found++;
            }
            mf[s[i]]++;
            bool f = false;
            while(j <= i && found == req){
                f = true;
                //ans++;
                mf[s[j]]--;
                if(mf[s[j]] == 0){
                    mf.erase(s[j]);
                    found--;
                }
                j++;
            }
            //if(f){
                // cout << "j: " << j - 1 << ", i: " << i << endl;
                // cout << "ans: " << j << endl;
                ans += j;
            //}
        }
        return ans;
    }
};