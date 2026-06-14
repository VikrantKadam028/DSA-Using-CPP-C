class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        int squareSum = 0;

        string digit = to_string(n);
        for (char c : digit) {
            digitSum += c - '0';
            squareSum += (c - '0') * (c - '0');
        }

        if (squareSum - digitSum >= 50) {
            return true;
        }

        return false;
    }
};