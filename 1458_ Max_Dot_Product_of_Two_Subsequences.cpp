class Solution {
public:
    int m, n;
    int dp[501][501];

    int solve(vector<int>& a, vector<int>& b, int i, int j) {
        if (i == m || j == n) {
            return INT_MIN;
        }

        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        int takeBoth = a[i] * b[j] +
                       max(0, solve(a, b, i + 1, j + 1));

        int skipA = solve(a, b, i + 1, j);
        int skipB = solve(a, b, i, j + 1);

        return dp[i][j] = max({takeBoth, skipA, skipB});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        for (int i = 0; i < 501; i++)
            for (int j = 0; j < 501; j++)
                dp[i][j] = INT_MIN;

        return solve(nums1, nums2, 0, 0);
    }
};
