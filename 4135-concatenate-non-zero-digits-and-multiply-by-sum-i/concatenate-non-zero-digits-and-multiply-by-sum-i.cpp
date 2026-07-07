class Solution {
public:
    char helper(int i){
        char ans = i + '0';
        return ans;
    }
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string temp;
        long long x = 0;
        long long sum = 0;
        while(n){
            sum += n%10;
            if(n%10 != 0)
                temp = helper(n%10) + temp;
            n /= 10;
        }
        x = stoi(temp);
        return x*sum;
    }
};