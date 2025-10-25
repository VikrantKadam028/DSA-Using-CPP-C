class Solution {
public:
    bool isAnagram(string s, string t) {
        // APPROACH 1
        //  map<char,int> mp1;
        //  map<char,int> mp2;

        // for(char ch:s){
        //     mp1[ch]++;
        // }
        // for(char ch:t){
        //     mp2[ch]++;
        // }
        // return mp1 == mp2;

        // APPROACH 2
        //  sort(s.begin(), s.end());
        //  sort(t.begin(), t.end());
        //  return s == t;

        // APPROACH 3
        if (s.size() != t.size())
            return false;
        if (s.size() != t.size())
            return false;

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;
        for (char c : t)
            freq[c - 'a']--;

        for (int f : freq) {
            if (f != 0)
                return false;
        }

        return true;
    }
};
