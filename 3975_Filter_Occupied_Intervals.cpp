class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        vector<vector<int>> ans;
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        int start = occupiedIntervals[0][0];
        int end = occupiedIntervals[0][1];
        for (int i = 1; i < occupiedIntervals.size(); i++) {
            if (occupiedIntervals[i][0] <= end+1) {
                end = max(end, occupiedIntervals[i][1]);
            } else {
                ans.push_back({start, end});
                start = occupiedIntervals[i][0];
                end = occupiedIntervals[i][1];
            }
        }

        ans.push_back({start, end});

        vector<vector<int>> result;
        for (int i = 0; i < ans.size(); i++) {
            int start = ans[i][0];
            int end = ans[i][1];

            // no overlap
            if (end < freeStart || start > freeEnd) {
                result.push_back({start, end});
            }
            // free interval is inside occupied interval
            else if (start < freeStart && end > freeEnd) {
                result.push_back({start, freeStart - 1});
                result.push_back({freeEnd + 1, end});
            }
            // overlap on right
            else if (start < freeStart) {
                result.push_back({start, freeStart - 1});
            }
            // overlap on left
            else if (end > freeEnd) {
                result.push_back({freeEnd + 1, end});
            }
        }

        return result;
    }
};