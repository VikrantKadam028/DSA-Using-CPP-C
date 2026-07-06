class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[intervals[i][0]] = i;
        }

        if (intervals.size() <= 1 && intervals[0][0] != intervals[0][1])
            return {-1};
        

            vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            int miniS = INT_MAX;
            int idx = -1;

            for (int j = 0; j < n; j++) {
                int nextS = intervals[j][0];
                int nextE = intervals[j][1];

                // right interval
                if (nextS >= end) {
                    miniS = min(miniS, nextS);
                }
            }

            result[i] = miniS == INT_MAX ? -1 : freq[miniS];
        }

        return result;
    }
};