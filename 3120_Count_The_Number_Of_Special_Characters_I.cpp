class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        int cnt = 0;
        for (char c : word) {
            mp[c]++;
        }

        for (auto& it : mp) {
            char ch;
            if (islower(it.first))
                ch = toupper(it.first);
            else if (isupper(it.first))
                ch = tolower(it.first);

            if (mp.find(ch) != mp.end())
                cnt++;
        }

        return cnt / 2;
    }
};