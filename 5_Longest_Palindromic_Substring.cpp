class Solution {
public:
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string result = "";

        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < s.length(); j++){

                if(s[i] == s[j]){
                    if(isPalindrome(s, i, j) && (j - i + 1 > result.length())){
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return result;
    }
};