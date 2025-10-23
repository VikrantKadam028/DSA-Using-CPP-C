class Solution {
public:
    bool checkStrings(string s1, string s2)  {
        unordered_map<char, int> d1_e, d1_o;
        unordered_map<char, int> d2_e, d2_o;

        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                d1_e[s1[i]]++;
                d2_e[s2[i]]++;
            } else {
                d1_o[s1[i]]++;
                d2_o[s2[i]]++;
            }
        }
        return d1_e == d2_e && d1_o == d2_o;
    }
};
