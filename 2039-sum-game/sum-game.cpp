class Solution {
public:
    bool sumGame(string num) {
        // ??67791?
        // 13 - 17
        // dono taraf mei ? hai toh bada wala + 9 by alice
        // aur bob equalize toh chhoti wali jagah pe barabar
        // gap < 9 (9)
        // gap >= 9 (0)

        int lq = 0;
        int rq = 0;
        int rs = 0;
        int ls = 0;
        int n = num.length();

        for(int i = 0; i < (n/2); i++){
            if(num[i] == '?'){
                lq++;
                continue;
            }
            ls += (num[i] - '0');
        }
        for(int i = n/2; i < n; i++){
            if(num[i] == '?'){
                rq++;
                continue;
            }
            rs += (num[i] - '0');
        }
        return 2 * (ls - rs) != 9 * (rq - lq);
    }
};