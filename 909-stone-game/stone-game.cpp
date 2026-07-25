class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int A = 0;
        int B = 0;
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int k = 0;
        for(int i = n - 1; i >= 0; i--, k++){
            if(k % 2 == 0){
                A += piles[i];
            }
            else{
                B += piles[i];
            }
        }
        return (A > B);
    }
};