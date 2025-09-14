class Solution {
public:
    bool isValid(string word) {
        string vowels = "aeiouAEIOU";
        string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
        string digits = "0123456789";

        if(word.length() < 3) return false;

        bool hasVowel = false, hasConsonant = false;

        for(char ch : word) {
            if(vowels.find(ch) != string::npos) {
                hasVowel = true;
            } 
            else if(consonants.find(ch) != string::npos) {
                hasConsonant = true;
            }
            else if(digits.find(ch) != string::npos) {
                continue; 
            } 
            else {
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
};
