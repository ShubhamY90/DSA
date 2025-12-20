class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        for(int i = 0; i < s.length(); i++){
            string word;
            if(s[i] != ' '){
                //word += s[i];
                while(i < s.length() && s[i] != ' '){
                    word += s[i];
                    i++;
                }
                i--;
                words.push_back(word);
            }
        }
        reverse(words.begin(), words.end());
        string ans;
        for(auto word : words){
            ans += word;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};