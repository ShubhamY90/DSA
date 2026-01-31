class Solution {
public:
    char binary(vector<char>& letters, char target){
        int l = 0;
        int r = letters.size() - 1;
        char ans = letters[0];
        while(l <= r){
            int mid = (l + r)/2;
            if(letters[mid] > target){
                ans = letters[mid];
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        // for(auto c : letters){
        //     if(c > target){
        //         return c;
        //     }
        // }
        return binary(letters, target);
    }
};