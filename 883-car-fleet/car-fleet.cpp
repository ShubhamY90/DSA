class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> ps;
        for(int i = 0; i < n; i++){
            ps.push_back({position[i], speed[i]});
        }
        sort(ps.begin(), ps.end());
        int ans = 1;
        int minE = target;
        double time = (double)(target - ps[n - 1].first)/(double)ps[n - 1].second;
        for(int i = n - 2; i >= 0; i--){
            double temp = (double)(minE - ps[i].first)/(double)ps[i].second;
            //cout << "time: " << time << ", temp: " << temp << endl;
            if(temp > time){
                ans++;
                time = temp;
            }
        }
        return ans;

    }
};