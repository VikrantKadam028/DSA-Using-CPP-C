class Solution {
public:
    long long removeZeros(long long n) {
        string digit = to_string(n);
        string result = "";
        for (char c : digit) {
            if (c != '0') {
                result.push_back(c);
            }
        }
        return stoll(result);
    }
};
