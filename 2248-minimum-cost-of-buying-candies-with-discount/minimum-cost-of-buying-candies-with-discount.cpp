class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n == 1) return cost[0];
        if(n == 2) return cost[0] + cost[1];
        sort(cost.begin(), cost.end());
        int sum = 0;
        int j = n - 1;
        for(int i = n - 1; i >= 1; i -= 3){
            int temp = cost[i] + cost[i - 1];
            cout << i << " + " << i - 1 << ", ";
            j = i - 2;
            sum += temp;
        }
        cout << j << endl;
        if(j == 2){
            sum += cost[0] + cost[1];
        }
        if(j == 1) sum += cost[0];
        return sum;
    }
};