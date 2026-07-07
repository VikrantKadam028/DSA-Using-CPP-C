class Solution {
public:
    string longestNiceSubstring(string s) {

        string longest = "";

        for (int i = 0; i < s.length(); i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < s.length(); j++) {
                freq[s[j]]++;

                bool nice = true;

                for (auto& it : freq) {

                    if (islower(it.first)) {
                        if (freq.find(toupper(it.first)) == freq.end()) {
                            nice = false;
                            break;
                        }
                    }

                    else if (isupper(it.first)) {
                        if (freq.find(tolower(it.first)) == freq.end()) {
                            nice = false;
                            break;
                        }
                    }
                }
                if (nice) {
                    string result = s.substr(i, j - i + 1);
                    if (result.size() > longest.size()) {
                        longest = result;
                    }
                }
            }
        }
        return longest;
    }
};