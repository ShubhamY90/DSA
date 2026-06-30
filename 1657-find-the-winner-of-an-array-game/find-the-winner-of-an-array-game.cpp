class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        k = min(k, n);
        queue<int> q;
        for(int i = 1; i < n; i++){
            q.push(arr[i]);
        }
        int ans = arr[0];
        int i = 0;
        while(i < k){
            int curr = q.front();
            q.pop();
            if(ans > curr){
                //cout << ans << " won against " << curr << endl;
                q.push(curr);
                i++;
                //cout << i << " for ans " << ans << endl;
            }
            else{
                i = 1;
                swap(ans, curr);
                //cout << ans << " won against " << curr << endl;
                q.push(curr);
            }
        }
        return ans;
    }
};