class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            if (!isVowel(s[start])){
                start++;
                continue;
            }

            if(!isVowel(s[end])){
                end--;
                continue;
            }

            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        return s;
    }
};
