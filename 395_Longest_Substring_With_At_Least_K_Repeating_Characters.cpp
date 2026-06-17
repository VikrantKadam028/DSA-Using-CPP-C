class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            int cnt = 0;
            unordered_map<char, int> mp;
            for (int j = i; j < s.length(); j++) {
                mp[s[j]]++;

                bool valid = true;
                for (auto it : mp) {
                    if (it.second < k) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};