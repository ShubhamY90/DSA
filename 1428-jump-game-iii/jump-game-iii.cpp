class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<bool> visited(n, false);
        visited[start] = true; 
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(arr[temp] == 0){
                return true;
            }
            if(temp - arr[temp] >= 0 && !visited[temp - arr[temp]]){
                q.push(temp - arr[temp]);
                visited[temp - arr[temp]] = true;
            }
            if(temp + arr[temp] < n && !visited[temp + arr[temp]]){
                q.push(temp + arr[temp]);
                visited[temp + arr[temp]] = true;
            }
        }
        return false;
    }
};