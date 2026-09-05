class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int minIndex = INT_MAX;
        int n = nums.size();

        vector<int> maxi(n, 0);
        vector<int> mini(n, 0);

        maxi[0] = nums[0];
        // for max - Left to right
        for (int i = 1; i < n; i++) {
            maxi[i] = max(maxi[i - 1], nums[i]);
        }

        mini[n - 1] = nums[n - 1];

        // for min - Right to left
        for (int i = n - 2; i >= 0; i--) {
            mini[i] = min(mini[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if ((maxi[i] - mini[i]) <= k) {
                minIndex = min(minIndex, i);
            }
        }

        return minIndex == INT_MAX ? -1 : minIndex;
    }
};