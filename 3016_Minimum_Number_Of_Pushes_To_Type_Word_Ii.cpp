class Solution {
public:
    int minimumPushes(string word) {
        int result = 0;
        unordered_map<char, int> mpp;

        for (char c : word) {
            mpp[c]++;
        }

        // sort descending by val
        vector<pair<char, int>> freq(mpp.begin(), mpp.end());

        sort(freq.begin(), freq.end(),
             [](auto& a, auto& b) { return a.second > b.second; });

        int idx = 0;
        int pushes =0;
        for (auto& it : freq) {
            pushes = idx / 8 + 1;
            result += pushes * it.second;
            idx++;
        }
        return result;
    }
};