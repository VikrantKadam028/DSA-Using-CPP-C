class Solution {
public:
    int countAsterisks(string s) {
        bool inside = false;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '|' && inside == false) {
                inside = true;
            } else if (s[i] == '|' && inside == true) {
                inside = false;
            }
            if (!inside) {
                if (s[i] == '*')
                    cnt++;
            }
        }

        return cnt;
    }
};