class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int lW = k;
        int w = 0;
        for(int i = 0; i < k; i++){
            if(blocks[i] == 'W') w++;
        }
        lW = min(lW, w);
        for(int i = k; i < n; i++){
            if(blocks[i - k] == 'W') w--;
            if(blocks[i] == 'W') w++;
            lW = min(lW, w);
        }
        return lW;
    }
};