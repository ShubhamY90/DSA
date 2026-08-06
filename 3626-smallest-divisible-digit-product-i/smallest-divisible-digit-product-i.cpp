class Solution {
public:
    int helper(int n){
        int ans = 1;
        while(n){
            int temp = n%10;
            ans *= temp;
            n /= 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i <= 200; i++){
            int temp = helper(i);
            if(temp%t == 0) return i;
        }
        return -1;
    }
};