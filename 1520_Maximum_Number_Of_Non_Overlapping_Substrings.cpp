class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        unordered_map<char, int> mpp;
        unordered_map<char, vector<int>> StartEnd;

        vector<string> result;

        for (char c : s) {
            mpp[c]++;
        }

        for (int k = 0; k < s.length(); k++) {
            StartEnd[s[k]].push_back(k);
        }

        unordered_map<char, pair<int, int>> SEPairs;

        for (auto& it : StartEnd) {

            vector<int> temp = it.second;

            int start = temp[0];
            int end = temp[temp.size() - 1];

            SEPairs[it.first] = {start, end};
        }

        vector<pair<int, int>> intervals;

        for (auto& it : SEPairs) {

            int x = it.second.first;
            int y = it.second.second;

            bool valid = true;

            for (int k = x; k <= y; k++) {

                char c = s[k];

                if (SEPairs[c].first < x) {
                    valid = false;
                    break;
                }

                y = max(y, SEPairs[c].second);
            }

            if (valid) {
                intervals.push_back({x, y});
            }
        }

        sort(intervals.begin(), intervals.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second < b.second;
             });

        int i = -1;
        int j = -1;

        for (auto& interval : intervals) {

            int x = interval.first;
            int y = interval.second;

            if (j < x) {

                string str = "";

                for (int k = x; k <= y; k++) {
                    str += s[k];
                }

                result.push_back(str);

                i = x;
                j = y;
            }
        }

        return result;
    }
};