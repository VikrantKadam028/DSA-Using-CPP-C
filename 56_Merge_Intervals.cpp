class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // OPTIMAL
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        int Istart = intervals[0][0];
        int Iend = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= Iend) {
                Iend = max(Iend, intervals[i][1]);

            } else {
                ans.push_back({Istart, Iend});
                Istart = intervals[i][0];
                Iend = intervals[i][1];
            }
        }

        ans.push_back({Istart, Iend});

        return ans;

        // BRUTE
        //  vector<vector<int>> ans;
        //  int n = intervals.size();
        //  sort(intervals.begin(), intervals.end());
        //  for (int i = 0; i < n; i++) {
        //      int start = intervals[i][0];
        //      int end = intervals[i][1];

        //     int j;
        //     for (j = i + 1; j < n; j++) {
        //         if (intervals[j][0] <= end) {
        //             end = max(end, intervals[j][1]);
        //         } else {
        //             break;
        //         }
        //     }

        //     ans.push_back({start, end});

        //     i = j - 1; // we do this bcoz suppose j is at j = 2, and i = 1 if
        //     we
        //                // do j - 1 then i = 1 and
        //     // the outer loop automatically increments the i value to 2
        //     (i++).
        //     // So, we skip the intervals that are merged.
        // }

        // return ans;
    }
};