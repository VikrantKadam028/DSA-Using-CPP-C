class Solution {
public:
    int maximumLength(string s) {
        map<string, int> freq;
        string curr = "";

        for (int i = 0; i < s.length(); i++) {
            curr = "";
            for (int j = i; j < s.length(); j++) {
                if (s[i] != s[j]) {
                    curr = "";
                    break;
                }

                curr += s[j];
                freq[curr]++;
            }
        }

        int longest = -1;
        for (auto& it : freq) {
            if (it.second >= 3) {
                int n = it.first.size();
                longest = max(longest, n);
            }
        }

        return longest;
    }
};