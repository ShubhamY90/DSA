class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char, int> mp1, mp2;

        for (char c : word1) mp1[c]++;
        for (char c : word2) mp2[c]++;

        
        for (auto &it : mp1) {
            if (!mp2.count(it.first))
                return false;
        }

        vector<int> freq1, freq2;

        for (auto &it : mp1)
            freq1.push_back(it.second);

        for (auto &it : mp2)
            freq2.push_back(it.second);

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};