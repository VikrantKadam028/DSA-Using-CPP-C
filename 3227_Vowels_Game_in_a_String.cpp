class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (isVowel(c)) {
                return true;   
            }
        }
        return false;         
    }
    
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
