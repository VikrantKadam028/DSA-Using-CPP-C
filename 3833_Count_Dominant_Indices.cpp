class Solution {
public:
    float getAvg(int start, int end, vector<int>& nums) {
        int total = 0;
        float sum = 0;
        for (int i = start; i <= end; i++) {
            sum += nums[i];
            total++;
        }
        return sum/total;
    }
    int dominantIndices(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > getAvg(i+1, nums.size() - 1, nums)) {
                count++;
            }
        }
        return count;
    }
};
