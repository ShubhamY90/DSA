class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> found(n, false);
        found[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i = 0; i < rooms[curr].size(); i++){
                if(found[rooms[curr][i]]) continue;
                found[rooms[curr][i]] = true;
                q.push(rooms[curr][i]);
            }
        }
        for(int i = 0; i < n; i++){
            if(!found[i]) return false;
        }
        return true;
    }
};