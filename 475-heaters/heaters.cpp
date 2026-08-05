class Solution {
public:
    bool helper(vector<int>& houses, vector<int>& heaters, int r) {
        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);

            bool ok = false;

            if (it != heaters.end() && abs(*it - house) <= r)
                ok = true;

            if (it != heaters.begin()) {
                --it;
                if (abs(*it - house) <= r)
                    ok = true;
            }

            if (!ok)
                return false;
        }

        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());

        int l = 0;
        int r = 1000000000;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (helper(houses, heaters, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};