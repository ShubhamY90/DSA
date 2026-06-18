class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();

        bool hasOne = false;
        for (int x : nums) {
            if (x == 1) {
                hasOne = true;
                break;
            }
        }

        if (!hasOne) {
            return ((n + 1)/ 2);
        }

        int ans = 0;
        int i = 0;

        // leading zeros
        if (nums[0] == 0) {
            int len = 0;
            while (i < n && nums[i] == 0) {
                len++;
                i++;
            }
            if(len == 1) ans += 0;
            else ans += (len + 2) / 3;
        }

        while (i < n) {
            if (nums[i] == 1) {
                int j = i + 1;

                while (j < n && nums[j] == 0)
                    j++;

                int len = j - i - 1;

                if (len > 0) {
                    if (j == n) {
                        // trailing zeros
                        if(len == 1) ans += 0;
                        else ans += (len + 2) / 3;
                    } else {
                        // zeros between two 1s
                        if(len == 1 || len == 2) ans += 0;
                        else if(len % 2 != 0) ans += (len + 2)/3;
                        else ans += (len + 1) / 3;
                    }
                }

                i = j;
            } else {
                i++;
            }
        }

        return ans;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(solve(flowerbed) >= n) return true;
        return false;
    }
};