class Solution {
public:

    /*
        stored ranges and sorted them 
        now pushing the end of range in pq according to if start is <= the current end
        taking the highest and making it current end 
        for each highest end popped we increase the ans
        as each popped value represent a tap opened
    */

    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> r(n + 1);
        for(int i = 0; i <= n; i++){
            int t1 = i - ranges[i];
            int t2 = i + ranges[i];
            r[i] = {t1, t2};
        }
        sort(r.begin(), r.end(), [](pair<int, int> a, pair<int, int> b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        for(int i = 0; i <= n; i++){
            cout << r[i].first << " " << r[i].second << endl;
        }
        
        

        priority_queue<int> pq;   // stores ends

        int i = 0;
        int end = 0;
        int ans = 0;

        while (end < n) {

            while (i < r.size() && r[i].first <= end) {
                pq.push(r[i].second);
                i++;
            }

            if (pq.empty())
                return -1;

            end = pq.top();
            pq.pop();
            ans++;
        }

        return ans;
    }
};