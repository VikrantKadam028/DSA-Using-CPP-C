class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int n : arr) {
            freq[n]++;
        }
        unordered_set<int> s;

        for (auto it : freq) {
            s.insert(it.second);
        }
        return freq.size() == s.size();
    }
};
