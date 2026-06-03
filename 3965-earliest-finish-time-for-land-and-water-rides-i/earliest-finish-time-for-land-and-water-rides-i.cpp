class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minL = INT_MAX;
        for(int i = 0; i < n; i++){
            minL = min(minL, landStartTime[i] + landDuration[i]);
        }
        int minW = INT_MAX;
        for(int i = 0; i < m; i++){
            minW = min(minW, waterStartTime[i] + waterDuration[i]);
        }
        int ans1 = INT_MAX;
        for(int i = 0; i < m; i++){
            if(waterStartTime[i] >= minL){
                ans1 = min(ans1, waterStartTime[i] + waterDuration[i]);
            }
            else{
                ans1 = min(ans1, minL + waterDuration[i]);
            }
        }
        int ans2 = INT_MAX;
        for(int i = 0; i < n; i++){
            if(landStartTime[i] >= minW){
                ans2 = min(ans2, landStartTime[i] + landDuration[i]);
            }
            else{
                ans1 = min(ans1, minW + landDuration[i]);
            }
        }
        return min(ans1, ans2);
    }
};