class Solution {
public:
    bool isPalindromic(string s) {
        string result = "";

        for (char c : s) {

            bitset<8> binary((int)c);
            result += binary.to_string();
        }

        string rev = result;
        reverse(rev.begin(), rev.end());
        return result == rev;
    }
};