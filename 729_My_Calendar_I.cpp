class MyCalendar {
private:
    vector<vector<int>> intervals;
    int start, end;

public:
    MyCalendar() {
        start = 0;
        end = 0;
    }

    bool book(int startTime, int endTime) {
       sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            if (startTime < end && endTime > start) {
                return false;
            }
        }

        intervals.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */