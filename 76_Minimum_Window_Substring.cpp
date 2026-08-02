class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;

        for (int i = 0; i < t.length(); i++) {
            mpp[t[i]]++;
        }

        int cnt = 0;
        int l = 0, r = 0;
        int minlen = INT_MAX;

        string result = "";
        int startIdx = -1;

        while (r < s.length()) {
            if (mpp[s[r]] > 0) {
                cnt++;
            }

            mpp[s[r]]--;

            while (l < s.length() && cnt == t.length()) {
                mpp[s[l]]++;
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    startIdx = l;
                }

                if (mpp[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }

            r++;
        }

        return startIdx == -1 ? "" : s.substr(startIdx, minlen);
    }
};