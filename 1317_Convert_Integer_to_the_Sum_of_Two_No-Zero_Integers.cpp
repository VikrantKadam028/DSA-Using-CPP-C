class Solution {
public:
    bool hasZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return true;
            num /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int a = i;
            int b = n - i;
            if (!hasZero(a) && !hasZero(b)) {
                return {a, b};  
            }
        }
        return {};
    }
};
