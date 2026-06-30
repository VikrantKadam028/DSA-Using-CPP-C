class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int result = 0;
        int n = s.length();

        while (j < s.length()) {

            char ch = s[j];
            mp[s[j]]++;

            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                result += (n - j);
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return result;
    }
};