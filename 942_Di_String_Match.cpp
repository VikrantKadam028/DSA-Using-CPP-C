class Solution {
public:
    vector<int> diStringMatch(string s) {
        int dec = s.length();
        int inc = 0;
        vector<int> result;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'D') {
                result.push_back(dec);
                dec--;
            } else if (s[i] == 'I') {
                result.push_back(inc);
                inc++;
            }
        }
        result.push_back(inc);
        return result;
    }
};