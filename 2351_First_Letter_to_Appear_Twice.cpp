class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> seen;

        for(char ch: s){
            if(seen.count(ch)){
                return ch;
            }else{
                seen.insert(ch);
            }
        }
        return ' ';
    }
};
