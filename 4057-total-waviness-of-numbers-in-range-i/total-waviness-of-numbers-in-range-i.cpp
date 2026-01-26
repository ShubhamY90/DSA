class Solution {
public:
    int check(int num){
        string n = to_string(num);
        int ans = 0;
        for(int i = 1; i < n.length() - 1; i++){
            if((n[i - 1] < n[i] && n[i] > n[i + 1]) || (n[i - 1] > n[i] && n[i] < n[i + 1])){
                ans++;
            }
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i <= num2; i++){
            ans += check(i);
        }
        return ans;
    }
};