class Solution {
public:
    int minimumPushes(string word) {
        int l = word.length();
        int sec = (l + 7)/8;
        int ans = 0;
        int temp = 8;
        for(int i = 0; i < sec - 1; i++){
            ans += temp;
            temp += 8;
            cout << ans << " temp: " << temp << endl;
        }
        for(int i = 0; i < (l - (sec - 1)*8); i++){
            ans += (temp/8);
        }
        return ans;
    }
};