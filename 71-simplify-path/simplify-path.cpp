class Solution {
public:
    string simplifyPath(string path) {
        stack<char> s;
        string ans;
        int i = 0;
        int n = path.length();

        s.push('/');

        while (i < n) {
            while (i < n && path[i] == '/')
                i++;

            if (i >= n)
                break;

            string token;
            while (i < n && path[i] != '/') {
                token += path[i];
                i++;
            }

            if (token == ".") {
                continue;
            } 
            else if (token == "..") {
                if (s.size() == 1)
                    continue;

                while (!s.empty() && s.top() != '/')
                    s.pop();

                if (s.size() > 1 && s.top() == '/')
                    s.pop();
            } 
            else {
                if (s.top() != '/')
                    s.push('/');

                for (char c : token)
                    s.push(c);
            }
        }

        if (s.size() > 1 && s.top() == '/')
            s.pop();

        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};