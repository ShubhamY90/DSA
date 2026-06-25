class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;

        // Build graph: ingredient -> recipes
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();

            for (string &ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
        }

        queue<string> q;

        // Initial supplies
        for (string &s : supplies) {
            q.push(s);
        }

        vector<string> ans;

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            for (string &recipe : graph[cur]) {
                indegree[recipe]--;

                if (indegree[recipe] == 0) {
                    ans.push_back(recipe);
                    q.push(recipe);   // Recipe becomes a new supply
                }
            }
        }

        return ans;
    }
};