class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int left = 0, right = 0;
        unordered_map<int, int> mp;
        int longest = INT_MIN;
        // bool isPossible = true;

        while (right < n) {
            // isPossible = true;
            mp[nums[right]]++;
            right++;

            // got TLE
            //  for (auto& it : mp) {
            //      if (it.second > k) {
            //          isPossible = false;
            //          mp[nums[left]]--;
            //          left++;
            //          break;
            //      }
            //  }

            while (mp[nums[right - 1]] > k) {
                mp[nums[left]]--;
                left++;
            }
            longest = max(longest, right - left);

            // if (isPossible) {
            //     longest = max(longest, right - left);
            // }
        }
        return longest;
    }
};