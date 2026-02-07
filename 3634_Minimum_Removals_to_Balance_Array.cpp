class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1)
            return 0;

        sort(nums.begin(), nums.end());

        vector<int> result;

        int maxLen = 0;
        int left_idx = 0;
        int right = 0;

        while (right < n) {
            if (right < n &&
                (left_idx >= (int)result.size() ||
                 (long long)nums[right] <= (long long)result[left_idx] * k)) {
                result.push_back(nums[right]);
                right++;
                int currentSize = (int)result.size() - left_idx;
                maxLen = max(maxLen, currentSize);
            } else {

                left_idx++;
            }
        }

        int finalSize = (int)result.size() - left_idx;
        maxLen = max(maxLen, finalSize);

        return n - maxLen;
    }
};
