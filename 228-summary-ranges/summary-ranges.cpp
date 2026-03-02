class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        for(int i = 0; i < n; i++){
            string temp;
            //temp.push_back('"');
            temp += to_string(nums[i]);
            
            int t = nums[i];
            int j = i + 1;
            for(; j < n; j++){
                if(nums[j] != nums[j - 1] + 1) break;
                t = nums[j];
                
            }
            if(t != nums[i]){
                temp += "->";
                temp+= to_string(t);
            }
            //temp.push_back('"');
            ans.push_back(temp);
            i = j - 1;
        }
        return ans;
    }
};