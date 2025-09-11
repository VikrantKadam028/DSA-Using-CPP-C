class Solution {
public:
    string sortVowels(string s) {
        vector<int> ascii;

        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                ascii.push_back((int)s[i]);
            }
        }
        sort(ascii.begin(), ascii.end());

        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = (char)ascii[index++];
            }
        }
        return s;
    }

private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' ||
               ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U';
    }
};


#endif
