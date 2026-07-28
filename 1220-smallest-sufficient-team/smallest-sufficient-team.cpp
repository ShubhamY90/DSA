class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {

        unordered_map<string, int> mp;

        int m = req_skills.size();

        for (int i = 0; i < m; i++)
            mp[req_skills[i]] = i;

        int fullMask = (1 << m);

        vector<int> personMask(people.size());

        for (int i = 0; i < people.size(); i++) {
            int mask = 0;

            for (auto &skill : people[i]) {
                if (mp.count(skill))
                    mask |= (1 << mp[skill]);
            }

            personMask[i] = mask;
        }

        vector<vector<int>> dp(fullMask);

        vector<bool> vis(fullMask, false);
        vis[0] = true;

        for (int mask = 0; mask < fullMask; mask++) {

            if (!vis[mask])
                continue;

            for (int i = 0; i < people.size(); i++) {

                int newMask = mask | personMask[i];

                if (!vis[newMask] ||
                    dp[newMask].size() > dp[mask].size() + 1) {

                    vis[newMask] = true;
                    dp[newMask] = dp[mask];
                    dp[newMask].push_back(i);
                }
            }
        }

        return dp[fullMask - 1];
    }
};