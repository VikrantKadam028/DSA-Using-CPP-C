class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> result;

        unordered_map<int, string> freq;

        for (int i = 0; i < names.size(); i++) {
            freq[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end(), greater<int>());

        for (int i = 0; i < names.size(); i++) {
            result.push_back(freq[heights[i]]);
        }
        return result;
    }
};