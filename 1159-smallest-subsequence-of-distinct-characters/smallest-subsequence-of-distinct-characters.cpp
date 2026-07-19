class Solution {
public:
    /* same as 316
        took a stack (can also use a string as stack)
        now pushing until we are getting the last char < current char
        but anywhere it is reversed we pop if that char appears later
        and pop until the stack is empty or we find a char that is smaller than current char 
        we push only once a char and mark the pushed char as present and 
        if we remove it we unmark it
    */
    string smallestSubsequence(string s) {
        unordered_map<char, int> mp;
        vector<bool> present(26, false);
        stack<char> st;
        string ans;
        for(auto c : s){
            mp[c]++;
        }
        for(auto c : s){
            mp[c]--;
            if(present[c - 'a']) continue;

            else{
                while(!st.empty() && st.top() > c && mp[st.top()] > 0){
                    present[st.top() - 'a'] = false;
                    st.pop();
                }
                present[c - 'a'] = true;
                st.push(c);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};