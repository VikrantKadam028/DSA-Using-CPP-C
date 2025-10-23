class Solution {
public:
    bool hasSameDigits(string s) {
        if (s == "")
            return false;
        while (s.size() > 2) {
            string result = "";
            for (int i = 0; i < s.length() - 1; i++) {
                result += (s[i] + s[i + 1]) % 10;
            }
            s = result;
        }

        return s[0] == s[1];
    }
};
