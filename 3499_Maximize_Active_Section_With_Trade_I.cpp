class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // 1. First count the 0's before the 1 and after the 1's, and add it to
        // inactive vector.
        // 2. find the max sum pair from inactive.
        // 3. The return the total 1's cnt + maxi.
        int ones = count(begin(s), end(s), '1');
        int n = s.length();
        vector<int> inactive;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') {
                    i++;
                }

                inactive.push_back(i - start);
            } else {
                i++;
            }
        }

        int maxi = 0;
        for (int i = 1; i < inactive.size(); i++) {
            maxi = max(maxi, inactive[i] + inactive[i - 1]);
        }

        return ones + maxi;
    }
};