class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int light = *max_element(lights.begin(), lights.end());
        int waiting = 0;

        for (int i = 0; i < arrivalTime.size(); i++) {
            int r = arrivalTime[i] % period;

            if (r >= light) {
                waiting = max(waiting, period - r);
            }
        }
        return waiting;
    }
};