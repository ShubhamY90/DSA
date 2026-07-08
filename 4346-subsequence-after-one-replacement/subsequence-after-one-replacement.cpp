class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        if (n > m) return false;
        const int INF = m + 1;

        vector<int> front(n + 1);
        front[0] = 0;
        {
            int j = 0;
            bool failed = false;
            for (int i = 0; i < n; i++) {
                if (failed) { front[i+1] = INF; continue; }
                while (j < m && t[j] != s[i]) j++;
                if (j < m) { front[i+1] = j+1; j++; }
                else { front[i+1] = INF; failed = true; }
            }
        }

        vector<int> back(n + 1);
        back[n] = m;
        {
            int j = m - 1;
            bool failed = false;
            for (int i = n - 1; i >= 0; i--) {
                if (failed) { back[i] = -1; continue; }
                while (j >= 0 && t[j] != s[i]) j--;
                if (j >= 0) { back[i] = j; j--; }
                else { back[i] = -1; failed = true; }
            }
        }

        if (front[n] <= m) return true;   // already a subsequence

        for (int i = 0; i < n; i++)
            if (front[i] < back[i + 1]) return true;

        return false;
    }
};