class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if (c[mid] >= n - mid)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return n - l;
    }
};