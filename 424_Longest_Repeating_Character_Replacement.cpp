class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0, maxfreq = 0, maxlen = 0;
        unordered_map<char, int> freq;

        while (r < n) {
            freq[s[r]]++;

            maxfreq = max(maxfreq, freq[s[r]]);

            if (((r - l + 1) - maxfreq) > k) {
                freq[s[l]]--;
                maxfreq = 0;
                // for (auto& it : freq) {
                //     maxfreq = max(maxfreq, it.second);
                // }
                l++;
            }

            if (((r - l + 1) - maxfreq) <= k) {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};