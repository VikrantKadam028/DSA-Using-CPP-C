class Solution {
public:
    long long getSumPro(int n, bool isSum) {
        string str = to_string(n);
        long long result = 0;
        long long pro = 1;

        for (char c : str) {
            if (isSum == true) {
                result += c - '0';
            } else {
                pro *= c - '0';
            }
        }
        return isSum == true ? result : pro;
    }

    bool checkDivisibility(int n) {
        long long sum = getSumPro(n, true);
        long long pro = getSumPro(n, false);

        if (n % (sum + pro) == 0) {
            return true;
        }
        return false;
    }
};