class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums[0];

        long long maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {

                long long g = gcd(nums[i], nums[j]);
                long long gcdCal = 1LL * g * g;

                long long sum = (1LL * nums[i] * nums[j]) / gcdCal;

                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};