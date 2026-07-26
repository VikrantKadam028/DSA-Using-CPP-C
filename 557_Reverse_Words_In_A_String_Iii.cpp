class Solution {
public:
    string reverseWords(string s) {
        int l = 0;
        int r = 0;

        for (int i = 0; i < s.length(); i++) {
            while (r < s.length() && s[r] != ' ') {
                r++;
            }
            int start = l;
            int end = r - 1;
            while (start < end) {
                char ch = s[start];
                s[start] = s[end];
                s[end] = ch;
                start++;
                end--;
            }

            r = r + 1;
            l = r;
        }
        return s;
    }
};