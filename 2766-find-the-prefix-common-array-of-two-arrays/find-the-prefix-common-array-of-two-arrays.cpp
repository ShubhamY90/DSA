class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> map;
        int n = A.size();
        for(int i = 0; i < n; i++){
            map[A[i]] = i;
        }
        for(int i = 0; i < n; i++){
            map[B[i]] = max(i, map[B[i]]);
        }
        vector<int> ans(n, 0);
        for(int i = 1; i <= n; i++){
            ans[map[i]]++;
        }
        for(int i = 1; i < n; i++){
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};