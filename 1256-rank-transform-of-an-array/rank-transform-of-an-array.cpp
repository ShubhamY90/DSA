class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n < 1) return arr;
        vector<pair<int, int>> temp(n);
        for(int i = 0; i < n; i++){
            temp[i] = {arr[i], i};
        }
        sort(temp.begin(), temp.end());
        int rank = 1;
        arr[temp[0].second] = 1;
        for(int i = 1; i < n; i++){
            if(temp[i - 1].first == temp[i].first){
                arr[temp[i].second] = rank;
            }
            else{
                rank++;
                arr[temp[i].second] = rank;
            }
        }
        return arr;
    }
};