class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int windowSize = p.length();
        map<char, int> mpp2;

        for (char c : p) {
            mpp2[c]++;
        }

        int l = 0;
        int r = windowSize - 1;

        map<char, int> mpp;

        for (int i = 0; i < windowSize; i++) {
            mpp[s[i]]++;
        }

        vector<int> Indexes;

        if (mpp == mpp2) {
            Indexes.push_back(l);
        }
        mpp[s[l]]--;
        if (mpp[s[l]] == 0) {
            mpp.erase(s[l]);
        }
        l++;
        r++;
        mpp[s[r]]++;

        while (r < s.length()) {
            if (mpp == mpp2) {
                Indexes.push_back(l);
            }

            mpp[s[l]]--;
            if (mpp[s[l]] == 0) {
                mpp.erase(s[l]);
            }
            l++;
            r++;
            mpp[s[r]]++;
        }

        return Indexes;
    }
};