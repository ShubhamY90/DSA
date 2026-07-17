class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }

        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long cnt = 0;

            for (int j = g; j <= mx; j += g) {
                cnt += freq[j];
            }

            exact[g] = cnt * (cnt - 1) / 2;

            for (int j = 2 * g; j <= mx; j += g) {
                exact[g] -= exact[j];
            }
        }

        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            pref[i] = pref[i - 1] + exact[i];
        }

        vector<int> ans;

        for (long long q : queries) {
            int l = 1;
            int r = mx;

            while (l < r) {
                int mid = l + (r - l) / 2;

                if (pref[mid] > q) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            ans.push_back(l);
        }

        return ans;
    }
};