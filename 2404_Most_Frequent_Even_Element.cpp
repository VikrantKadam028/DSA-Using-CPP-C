class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mpp;
        int prev = -1;
        int first = -1;
        for (int n : nums) {
            mpp[n]++;
        }

        for (auto it : mpp) {
            if (it.first % 2 == 0) {
                if (it.second > prev) {
                    prev = it.second;
                    first = it.first;
                }
            }
        }

        return first;
    }
};