class Solution {
public:
    string maxWord(string w1, string w2) {
        return (w1.length() > w2.length()) ? w1 : w2;
    }

    string mergeAlternately(string word1, string word2) {
        int maxLen = max(word1.length(), word2.length());
        string result = "";

        for (int i = 0; i < maxLen; i++) {
            if (i < word1.length())
                result += word1[i];
            if (i < word2.length())
                result += word2[i];
        }
        return result;
    }
};
