class Solution {
public:
    void helper(string &num, long long target, int i, long long currVal, long long prev, string temp, vector<string> &ans) {
        if (i == (int)num.length()) {
            if (currVal == target) ans.push_back(temp);
            return;
        }

        long long val = 0;
        string part = "";

        for (int j = i; j < (int)num.length(); j++) {
            if (j > i && num[i] == '0') break;

            part.push_back(num[j]);
            val = val * 10 + (num[j] - '0');

            if (i == 0) {
                helper(num, target, j + 1, val, val, part, ans);
            } else {
                helper(num, target, j + 1, currVal + val, val, temp + "+" + part, ans);
                helper(num, target, j + 1, currVal - val, -val, temp + "-" + part, ans);
                helper(num, target, j + 1, currVal - prev + prev * val, prev * val, temp + "*" + part, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};
