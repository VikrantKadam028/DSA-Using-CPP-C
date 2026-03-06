class Solution {
public:
    bool checkOnesSegment(string s) {
        bool isZeroOne = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0' && s[i + 1] == '1') {
                isZeroOne = false;
            }
        }
        return isZeroOne;
    }
};
