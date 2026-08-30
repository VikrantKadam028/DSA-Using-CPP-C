class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        set<int> st;
        int l = 0;
        int r = 0;
        int cnt = 0;
        bool paired = false;

        unordered_map<int, int> freq;
        set<int> breakedBefore;

        for (int n : nums) {
            freq[n]++;
        }

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

            if (paired && cnt > 1 && freq[nums[r]] == 0) {
                if (breakedBefore.find(nums[r]) == breakedBefore.end()) {
                    st.insert(nums[r]);
                }
            }

            else if (nums[r] != nums[l]) {
                breakedBefore.insert(nums[l]);
                l = r;
                freq[nums[r]]++;
                r--;
                cnt = 0;
            }
            r++;
        }

        return st.size();
    }
};