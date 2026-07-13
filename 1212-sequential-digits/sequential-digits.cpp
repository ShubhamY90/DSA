class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = to_string(low);

        string temp1;
        for (int i = 0; i < s.length(); i++)
            temp1 += char('1' + i);

        int start = stoi(temp1);

        string temp3(s.length(), '1');
        int carry = stoi(temp3);

        vector<int> ans;

        while (start <= high) {

            if (start >= low)
                ans.push_back(start);

            if (temp1.back() == '9') {
                if (temp1.size() == 9)
                    break;

                temp3 += '1';
                carry = stoi(temp3);

                temp1.clear();
                for (int i = 0; i < temp3.size(); i++)
                    temp1 += char('1' + i);

                start = stoi(temp1);
            } else {
                temp1.erase(temp1.begin());
                temp1 += char(temp1.back() + 1);
                start = stoi(temp1);
            }
        }

        return ans;
    }
};