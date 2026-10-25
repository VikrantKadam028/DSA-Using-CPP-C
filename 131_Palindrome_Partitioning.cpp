class Solution {
public:
    void func(string s, vector<string>& partitions,
              vector<vector<string>>& ans) {
        if (s.empty()) {
            ans.push_back(partitions);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            string part = s.substr(0, i + 1);
            string rev = part;
            reverse(rev.begin(), rev.end());
            if (part == rev) { // is a palindrome
                partitions.push_back(part);
                func(s.substr(i + 1, s.length()), partitions, ans);
                partitions.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        if (s.empty())
            return {};

        vector<string> partitions;
        vector<vector<string>> ans;

        func(s,partitions, ans);

        return ans;
    };
};