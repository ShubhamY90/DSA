class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        unordered_map<int, int> opt;
        vector<vector<int>> cp;
        for(int i = 0; i < n; i++){
            opt[i] = (profits[i]);
            cp.push_back({capital[i], profits[i], i});
        }
        sort(cp.begin(), cp.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];   // second descending
            return a[0] < b[0];       // first ascending
        });
        int val = w;
        int done = 0;
        bool completed = false;
        priority_queue<int> heap;
        for(int i = 0; i < n; i++){
            if(cp[i][0] <= val) heap.push(opt[cp[i][2]]);
            else{
                if (heap.empty()){
                    completed = true;
                    break;
                }
                val += heap.top();
                heap.pop();

                //cout << i << " " << "curr capital: " << val << endl;
                done++;
                if(done == k){
                    completed = true;
                    break;
                }
                i--;
            }
        }
        if(completed) return val;
        else{
            while(done != k && !heap.empty()){
                val += heap.top();
                heap.pop();
                //cout << "curr capital: " << val << endl;
                done++;
                //cout << "done: " << done << endl;
                if(done == k){
                    break;
                }
            }
        }
        return val;
    }
};