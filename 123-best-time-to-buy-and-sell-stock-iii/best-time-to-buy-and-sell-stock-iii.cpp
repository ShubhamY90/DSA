class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = INT_MIN;
        int b2 = INT_MIN;
        int s1 = INT_MIN;
        int s2 = INT_MIN;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            b1 = max((-1)*prices[i], b1);
            s1 = max(s1, b1 + prices[i]);
            b2 = max(s1 + (-1)*prices[i], b2);
            s2 = max(b2 + prices[i], s2);
        }
        return s2;
    }
};