class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto word : words){
            int temp = 0;
            for(int i = 0; i < word.length(); i++){
                temp += weights[word[i] - 'a'];
            }
            temp %= 26;
            //cout << temp << endl;
            ans += static_cast<char>(26 - temp + 96);
        }
        return ans;
    }
};