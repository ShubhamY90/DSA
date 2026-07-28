class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int temp = -1;
        string ans = "";
        //using & here or it copies entire array again TLE
        auto &v = mp[key];
        //can use binary search function creating a seperate here
        auto it = upper_bound(
            v.begin(), v.end(), timestamp,
            [](int t, const pair<int, string>& p) {
                return t < p.first;
            }
        );
        if(it == v.begin()) return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */