class Solution {
public:
    int appendCharacters(string s, string t) {

        int idx = -1;
        int j = 0;
        for(int i=0;i<s.length() && j < t.length() ; i++){
            if(s[i] == t[j]){
                j++;
            }
        }

        idx = j;

        string result = "";

        for(int i=idx;i<t.length();i++){
            result += t[i];
        }
        return result.length();
    }
};