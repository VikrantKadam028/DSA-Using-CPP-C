class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& p : mp) {
            result.push_back(p.second);
        }

        return result;

        // TLE - 127/128 test cases passed
        //  bool isAnagram(string s1, string s2) {
        //      if (s1.size() != s2.size())
        //          return false;
        //      vector<int> freq(26, 0);

        //     for (char c : s1) {
        //         freq[c - 'a']++;
        //     }
        //     for (char c : s2) {
        //         freq[c - 'a']--;
        //     }

        //     for (int c : freq) {
        //         if (c != 0)
        //             return false;
        //     }
        //     return true;
        // }
        // vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //     vector<vector<string>> result;
        //     vector<bool> used(strs.size(), false);

        //     for (int i = 0; i < strs.size(); i++) {
        //         if (used[i])
        //             continue;
        //         vector<string> group;
        //         group.push_back(strs[i]);
        //         used[i] = true;
        //         for (int j = i + 1; j < strs.size(); j++) {
        //             if (!used[j] && isAnagram(strs[i], strs[j])) {
        //                 group.push_back(strs[j]);
        //                 used[j] = true;
        //             }
        //         }
        //         result.push_back(group);
        //     }
        //     return result;
    }
};
