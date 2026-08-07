class Solution {
public:
    int maxDistinct(string s) {
        vector<int> nums(26, 0);
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (nums[ch - 'a'] >= 1) {
                continue;
            }
            nums[ch - 'a'] = 1;
            cnt++;
        }
        return cnt;
    }
};