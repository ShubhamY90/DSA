class Solution {
public:
    int maxProduct(int n) {
        int t1 = -1;
        int t2 = -1;
        while(n){
            if(t1 == -1){
                t1 = n%10;
            }
            else{
                if(t1 < (n%10)){
                    t2 = t1;
                    t1 = n%10;
                }
                else if(t2 == -1){
                    t2 = n%10;
                }
                else if(t2 < (n%10)){
                    t2 = n%10;
                }
            }
            n /= 10;
        }
        return t1*t2;
    }
};