class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        int len = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            // cout << "arr[i]: " << arr[i] << ", 2*arr[i]: " << 2*arr[i] << endl;
            // cout << "mp[arr[i]]: " << mp[arr[i]] << ", mp[2*arr[i]]: " << mp[2*arr[i]] << endl;
            if(mp[2*arr[i]] > 0 && mp[arr[i]] > 0){
                if(2*arr[i] == arr[i] && mp[arr[i]] < 2) continue;
                mp[2*arr[i]]--;
                mp[arr[i]]--;
                len++;
                //cout << "len: " << len << endl;
            }
        }
        return (len >= n/2);
    }
};