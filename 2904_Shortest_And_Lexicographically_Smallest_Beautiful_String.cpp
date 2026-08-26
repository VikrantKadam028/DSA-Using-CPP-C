class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        if (k == 1) {
            bool allZeros = true;
            for (char c : s) {
                if (c == '1') {
                    allZeros = false;
                    break;
                }
            }
            if (allZeros) {
                return "";
            }
            return "1";
        }

        string preStr = "";
        int shortest = INT_MAX;
        int start = -1;
        int end = -1;

        for (int i = 0; i < s.length(); i++) {
            int ones = 0;
            string str = "";
            for (int j = i; j < s.length(); j++) {
                str += s[j];
                if (s[j] == '1') {
                    ones++;
                }
                if (ones == k) {
                    int pos = 0;
                    while (pos < str.length() && str[pos] == '0') {
                        pos++;
                    }

                    if (preStr == "" || ( j - (pos + i) + 1) < preStr.length()) {
                        start = i + pos;
                        end = j;
                        if (str.length() != preStr.length()) {
                            preStr = str;
                        }
                    } else if (str.length() == preStr.length() &&
                               str < preStr) {
                        preStr = str;
                        start = i + pos;
                        end = j;
                    }
                }
            }
        }

        if (start == -1 && end == -1) {
            return "";
        }

        string newStr = "";
        for (int i = start; i <= end; i++) {
            newStr += s[i];
        }
        return newStr;
    }
};