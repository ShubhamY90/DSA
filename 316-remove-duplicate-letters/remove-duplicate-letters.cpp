class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mp;
        stack<char> st;
        vector<bool> present(26, false);
        for(auto c : s){
            mp[c]++;
        }
        for(char c : s){
            if(!present[c - 'a'] && st.empty()){
                st.push(c);
                present[c - 'a'] = true;
                mp[c]--;
            }
            else if(!present[c - 'a'] && st.top() < c){
                st.push(c);
                present[c - 'a'] = true;
                mp[c]--;
            }
            else if(!present[c - 'a'] && st.top() > c){
                while(!st.empty() && mp[st.top()] > 0 && st.top() > c){
                    present[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(c);
                mp[c]--;
                present[c - 'a'] = true;
            }
            else{
                mp[c]--;
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};