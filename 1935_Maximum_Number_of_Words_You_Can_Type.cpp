class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> words;
        string word = "";

        for (char c : text) {
            if (c != ' ') {
                word += c;
            } else {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            bool canType = true;

            for (int j = 0; j < w.length(); j++) {
                char c = w[j];
                if (brokenLetters.find(c) != string::npos) {
                    canType = false;
                    break;
                }
            }
            if (canType) {
                count++;
            }
        }

        return count;
    }
};
