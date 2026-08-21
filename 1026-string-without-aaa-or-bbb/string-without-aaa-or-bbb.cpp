class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;

        while (a > 0 || b > 0) {

            bool canA = a > 0;
            bool canB = b > 0;

            int n = ans.size();

            // Cannot place a if last two are aa
            if (n >= 2 && ans[n - 1] == 'a' && ans[n - 2] == 'a')
                canA = false;

            // Cannot place b if last two are bb
            if (n >= 2 && ans[n - 1] == 'b' && ans[n - 2] == 'b')
                canB = false;

            if (canA && canB) {
                // Use the character with more remaining
                if (a >= b) {
                    ans += 'a';
                    a--;
                }
                else {
                    ans += 'b';
                    b--;
                }
            }
            else if (canA) {
                ans += 'a';
                a--;
            }
            else if (canB) {
                ans += 'b';
                b--;
            }
        }

        return ans;
    }
};