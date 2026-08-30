class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        // to store distinct elem's.
        set<int> st;
        int l = 0;
        int r = 0;
        int cnt = 0;
        bool paired = false;

        // freq of each elem to track if more elem exist ahead.
        unordered_map<int, int> freq;

        // to check if the curr block elem is not previously breaked before
        // (used).
        set<int> breakedBefore;

        for (int n : nums) {
            freq[n]++;
        }

        // as all single elem are also a block, add them.
        for (auto& it : freq) {
            if (it.second == 1) {
                st.insert(it.first);
            }
        }

        while (r < n) {
            paired = false;
            freq[nums[r]]--;
            if (nums[r] == nums[l]) {
                cnt++;
                paired = true;
            }

            // if a block, cnt > 1, and no same element ahead and not previously
            // breaked -> add to set.
            if (paired && cnt > 1 && freq[nums[r]] == 0) {
                if (breakedBefore.find(nums[r]) == breakedBefore.end()) {
                    st.insert(nums[r]);
                }
            }

            // if block breaked, then add that elem to breaked set to track
            // later.
            else if (nums[r] != nums[l]) {
                breakedBefore.insert(nums[l]);
                l = r;
                // inc bcoz the curr 'r' goes one step back and then again goes
                // ahead but as the curr r is already decremented at start, so
                // increment it once to maintain freq.
                freq[nums[r]]++;
                r--;
                cnt = 0;
            }
            r++;
        }

        return st.size();
    }
};