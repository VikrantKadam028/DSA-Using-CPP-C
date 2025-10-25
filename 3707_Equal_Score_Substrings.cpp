class Solution {
public:
    bool scoreBalance(string s) {
        map<char, int> mp;
        for (char c = 'a'; c <= 'z'; c++) {
            mp[c] = (c - 'a') + 1;
        }

        for (int mid = 1; mid < s.size(); mid++) {  
            string s1 = "", s2 = "";
            int sum1 = 0, sum2 = 0;

            for (int i = 0; i < s.size(); i++) {
                if (i < mid) {            
                    s1 += s[i];
                    sum1 += mp[s[i]];
                } else {
                    s2 += s[i];
                    sum2 += mp[s[i]];
                }
            }

            if (sum1 == sum2) return true;
        }

        return false;
    }
};
