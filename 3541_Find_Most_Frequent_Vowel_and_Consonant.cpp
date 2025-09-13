class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> VowelFreq;
        unordered_map<char, int> ConsoFreq;

        for (char ch : s) {
            if (isVowel(ch)) {
                VowelFreq[ch]++;
            } else if (isalpha(ch)) { 
                ConsoFreq[ch]++;
            }
        }

        int maxVowel = 0;
        if (!VowelFreq.empty()) {
            auto it = max_element(
                VowelFreq.begin(), VowelFreq.end(),
                [](const auto &a, const auto &b) {
                    return a.second < b.second;
                }
            );
            maxVowel = it->second;
        }

        int maxConso = 0;
        if (!ConsoFreq.empty()) {
            auto it = max_element(
                ConsoFreq.begin(), ConsoFreq.end(),
                [](const auto &a, const auto &b) {
                    return a.second < b.second;
                }
            );
            maxConso = it->second;
        }

        return maxVowel + maxConso;
    }

private:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
