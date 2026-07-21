class Solution {
public:
    int reverseDegree(string s) {
        long long sum = 0;
        long long alphabetpos = 0;
        long long string_pos = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            alphabetpos = (26 - (c - 'a'));
            string_pos = i + 1;

            sum += alphabetpos * string_pos;
        }
        return sum;
    }
};