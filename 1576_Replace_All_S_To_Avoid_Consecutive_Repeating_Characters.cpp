class Solution {
public:
    string modifyString(string s) {
        unordered_map<int, char> mpp;

        for (int i = 0; i < 26; i++) {
            mpp[i] = 'a' + i;
        }

        //edge case
        if (s.length() >= 26) {
            int idx = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '?') {
                    if (idx > 25) {
                        idx = 0;
                    }

                    s[i] = mpp[idx];
                    idx++;
                }
            }
            return s;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '?') {
                mpp.erase(s[i] - 'a');
            }
        }

        for (int i = 0; i < s.length(); i++) {
            int idx = 0;
            if (s[i] == '?') {
                for (int i = 0; i < 26; i++) {
                    if (mpp.find(i) != mpp.end()) {
                        idx = i;
                        break;
                    }
                }

                s[i] = mpp[idx];
                mpp.erase(idx);
            }
        }

        return s;
    }
};