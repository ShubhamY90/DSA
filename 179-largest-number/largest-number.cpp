class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            v[i] = to_string(nums[i]);
        }
        /*  sorted on the basis of 
            which string forms a greater int on combination
            example 324 and 32
            it will form 32432 and 32324 and sort on the basis of these 2 
        */
        sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        string ans;
        for(auto s : v){
            ans += s;
        }
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};