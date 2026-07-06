class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        int n = in.size();
        sort(in.begin(), in.end(), [](vector<int> a, vector<int> b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int ans = 0;
        int s = in[0][0];
        int e = in[0][1];
        for(int i = 1; i < n; i++){
            if(in[i][0] >= s && in[i][1] <= e){
                ans++;
            }
            else{
                s = in[i][0];
                e = in[i][1];
            }
        }
        return n - ans;

    }
};