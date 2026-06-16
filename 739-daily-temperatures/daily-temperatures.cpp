class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 1);
        ans[n - 1] = 0;
        int i = n - 2;
        for(; i >= 0; i--){
            if(t[i + 1] <= t[i]) ans[i] = 0;
            else break;
        }
        // for(int i = 0; i < n; i++){
        //     cout << ans[i] << ", ";
        // }
        cout << endl;
        //i++;
        stack<pair<int, int>> s;
        s.push({t[i + 1], i + 1});
        for(;i >= 0; i--){
            if(s.top().first > t[i]){
                //cout << "i: " << i << ", t[i]: " << t[i] << ", s.top(): " << s.top().first << endl;
                ans[i] = 1;
            }
            else{
                // cout << "i: " << i << endl;
                // cout << s.top().first << endl;
                // cout << "t[i]: " << t[i] << endl;
                vector<pair<int,int>> temp;
                while(!s.empty() && s.top().first <= t[i]){
                    //cout << " doing" << "...  -> ";
                    temp.push_back(s.top());
                    //cout << s.top().first << endl;
                    s.pop();
                }
                
                if(s.empty()){
                    ans[i] = 0;
                }
                else{
                    int temp2 = 0;
                    for(int k = 0; k < temp.size(); k++){
                        temp2 += ans[temp[k].second];
                    }
                    ans[i] = 1 + temp2;
                }
            }
            s.push({t[i], i});
        }
        return ans;
    }
};