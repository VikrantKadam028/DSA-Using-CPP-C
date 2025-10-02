class Solution {
public:
    string sortSentence(string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        while (ss >> word) {
            words.push_back(word);
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size() - i - 1; j++) {
                if (words[j].back() > words[j + 1].back()) {
                    swap(words[j], words[j + 1]);
                }
            }
        }

        for (int i = 0; i < words.size(); i++) {
            words[i].pop_back();
        }

        string sentence = "";
        for (int i = 0; i < words.size(); i++) {
            sentence += words[i];
            if (i != words.size() - 1) {
                sentence += " ";
            }
        }
        return sentence;
    }
};
