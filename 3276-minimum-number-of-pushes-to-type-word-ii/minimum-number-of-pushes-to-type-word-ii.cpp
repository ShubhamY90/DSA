class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        unordered_map<char, int> freq;
        for(int i = 0; i < n; i++){
            freq[word[i]]++;
        }
        vector<int> arr;
        for(auto it : freq){
            arr.push_back(it.second);
        }
        sort(arr.begin(), arr.end(), greater<int>());
        int temp = 1;
        int to_add = 1;
        int ans = 0;
        for(int i = 0; i < (int)arr.size(); i++){
            //cout << "char: " << arr[i] << ", to_add: " << to_add << endl;
            ans += to_add*arr[i];
            temp++;
            if(temp == 9){
                to_add++;
                temp = 1;
            }
        }
        return ans;
    }
};