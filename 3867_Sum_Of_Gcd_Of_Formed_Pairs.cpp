class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();

        int maxi = INT_MIN;

        vector<int> prefixGcd(n, 0);

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {
            sum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return sum;
    }
};