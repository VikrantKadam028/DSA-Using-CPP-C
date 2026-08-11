class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (int n : nums) {
            mpp[n]++;
        }

        int sum = 0;
        sum += nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == (nums[i - 1] + 1)) {
                sum += nums[i];
            } else {
                break;
            }
        }

        while (true) {
            if (mpp.find(sum) != mpp.end()) {
                sum++;
            } else {
                break;
            }
        }
        return sum;
    }
};