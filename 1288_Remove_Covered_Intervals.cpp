class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        int n = intervals.size();

        // our apprpach was failing for this test case : [[1,2],[1,4],[3,4]],
        // were the [0] is equal, so we sort if [0] is equal then keep the
        // largest end first.
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& x, vector<int>& y) {
                 if (x[0] == y[0])
                     return x[1] > y[1]; // larger end first
                 return x[0] < y[0];
             });

        int a = intervals[0][0];
        int b = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int c = intervals[i][0];
            int d = intervals[i][1];

            if (a <= c && d <= b) {
                cnt++;
            } else {
                a = c;
                b = d;
            }
        }

        return n - cnt;
    }
};