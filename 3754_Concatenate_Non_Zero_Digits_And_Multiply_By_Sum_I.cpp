class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n <= 0)
            return 0;
        long long sum = 0;
        string digits = to_string(n);
        string result = "";

        for (int i = 0; i < digits.length(); i++) {
            if (digits[i] != '0') {
                result += digits[i];
                sum += digits[i] - '0';
            }
        }

        return sum * stoi(result);
    }
};