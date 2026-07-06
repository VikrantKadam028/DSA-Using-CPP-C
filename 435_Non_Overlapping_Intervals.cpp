class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        int cnt = 0;

        for (int i = 1; i < intervals.size(); i++) {
            int nextStart = intervals[i][0];
            int nextEnd = intervals[i][1];

            if (end == nextStart) {
                start = nextStart;
                end = nextEnd;
                continue;
            }

            if (nextStart <= end) {
                cnt++;
                if (nextEnd < end) {
                    start = nextStart;
                    end = nextEnd;
                }
                continue;
            } else {
                start = nextStart;
                end = nextEnd;
            }
        }

        return cnt;
    }
};