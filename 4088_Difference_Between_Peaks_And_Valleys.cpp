class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int Speak = 0;
        int Svalley = 0;

        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                Speak += nums[i];
            }
            else if (nums[i] < nums[i-1] && nums[i] < nums[i+1]) {
                Svalley += nums[i];
            }
        }

        return Speak - Svalley;
    }
};