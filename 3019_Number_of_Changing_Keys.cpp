class Solution {
public:
    int countKeyChanges(string s) {
        int changes = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == toupper(s[i+1]) || s[i] == tolower(s[i+1])){
                continue;
            }else{
                changes++;
            }
        }
        return changes-1;
    }
};
