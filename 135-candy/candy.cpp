class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1){
            return 1;
        }
        vector<int> a(n, 1);
        if(ratings[0] > ratings[1]){
            a[0] = 2;
        }
        for(int i = 1; i < n - 1; i++){
            if(ratings[i - 1] < ratings[i]){
                a[i] = a[i - 1] + 1;
            }
            // else if(ratings[i] > ratings[i + 1]){
            //     a[i] = a[i + 1] + 1;
            // }
        }
        if(ratings[n - 1] > ratings[n - 2]){
            a[n - 1] = a[n - 2] + 1;
        }
        for(int i = n - 1; i >= 1; i--){
            if(ratings[i - 1] > ratings[i]){
                a[i - 1] = max(a[i - 1], a[i] + 1);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            //cout << a[i] << ",";
            ans += a[i];
        }

        return ans;
    }
};