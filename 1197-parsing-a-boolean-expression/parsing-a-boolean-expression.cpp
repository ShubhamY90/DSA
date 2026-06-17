class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {

            if (c == ',')
                continue;

            if (c != ')') {
                st.push(c);
                continue;
            }

            int t = 0, f = 0;

            while (st.top() != '(') {
                if (st.top() == 't')
                    t++;
                else if (st.top() == 'f')
                    f++;

                st.pop();
            }

            st.pop(); // remove '('

            char op = st.top();
            st.pop();

            char result;

            if (op == '!') {
                result = (f > 0) ? 't' : 'f';
            }
            else if (op == '&') {
                result = (f > 0) ? 'f' : 't';
            }
            else { // '|'
                result = (t > 0) ? 't' : 'f';
            }

            st.push(result);
        }

        return st.top() == 't';
    }
};