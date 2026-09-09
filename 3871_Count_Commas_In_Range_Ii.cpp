class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        if (n <= 999) {
            ans += 0;
        }
        else if (n <= 999999) {
            ans += n - 999;
           
        }
        else if (n <= 999999999) {
            long long rem = n - 999999;
            rem = rem * 2;

            ans += 999000 + rem;
        }
        else if (n <= 999999999999LL) {
            long long rem = n - 999999999;
            rem = rem * 3;

            ans += 999000 + 1998000000LL + rem;
        }
        else if (n <= 999999999999999LL) {
            long long rem = n - 999999999999LL;
            rem = rem * 4;

            ans += 999000 + 1998000000LL + 2997000000000LL + rem;
        }
        else if (n <= 999999999999999999LL) {
            long long rem = n - 999999999999999LL;
            rem = rem * 5;

            ans += 999000
                + 1998000000LL
                + 2997000000000LL
                + 3996000000000000LL
                + rem;
        }

        return ans;
    }
};