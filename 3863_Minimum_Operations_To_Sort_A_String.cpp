class Solution {
public:
    int minOperations(string s) {
        if (s.empty())
            return 0;

        //if sorted
        bool isSorted = true;
        char ch = s[0];
        for(int i=1;i<s.length();i++){
            if(ch > s[i]){
                isSorted = false;
                break;
            }
            ch = s[i];
        }

        if(isSorted){
            return 0;
        }

        if(s.length() == 2){
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if(s[0] == mn || s[s.length()-1] == mx){
            return 1;
        }

         for (int i = 1; i < s.length() - 1; i++) {
            if (s[i] == mn || s[i] == mx)
                return 2;
        }

        return 3;
    }
};