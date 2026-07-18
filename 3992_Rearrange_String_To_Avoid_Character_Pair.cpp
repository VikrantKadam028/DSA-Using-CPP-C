class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string result = "";

        for (char c : s) {
            if (y == c) {
                result += c;
            }
        }

        for (char c : s) {
            if (c != y) {
                result += c;
            }
        }
        return result;
    }
};