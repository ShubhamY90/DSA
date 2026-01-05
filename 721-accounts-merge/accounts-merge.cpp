class DSU {
    unordered_map<string, string> parent;
public:
    string find(string x) {
        if (parent.find(x) == parent.end()) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unionBS(string x, string y) {
        string px = find(x);
        string py = find(y);
        if (px != py) parent[py] = px;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        unordered_map<string, string> emailToName;
        
        // Step 1: Union emails within the same account
        for (auto &acc : accounts) {
            string name = acc[0];
            string firstEmail = acc[1];
            for (int i = 1; i < acc.size(); i++) {
                dsu.unionBS(firstEmail, acc[i]);
                emailToName[acc[i]] = name;
            }
        }
        
        // Step 2: Group emails by root parent
        unordered_map<string, set<string>> groups;
        for (auto &e : emailToName) {
            string root = dsu.find(e.first);
            groups[root].insert(e.first);
        }
        
        // Step 3: Form the final merged accounts
        vector<vector<string>> res;
        for (auto &p : groups) {
            vector<string> temp;
            temp.push_back(emailToName[p.first]); // Name
            temp.insert(temp.end(), p.second.begin(), p.second.end()); // Emails
            res.push_back(temp);
        }
        
        return res;
    }
};
