class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        int n = a.size();
        s.push(a[0]);
        int i = 1;
        while(i < n){
            if(!s.empty() && s.top() > 0 && a[i] < 0){
                if(s.top() > abs(a[i])){
                    i++;
                }
                else if(s.top() == abs(a[i])){
                    s.pop();
                    i++;
                }
                else{
                    s.pop();
                }
            }
            else{
                s.push(a[i]);
                i++;
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};