class Solution {
public:
    bool isValidSum(long long sum, int x) {
        int last = sum % 10;

        long long first = sum;
        while (first >= 10) {
            first /= 10;
        }

        return first == x && last == x;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long sum = 0;

            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];

                if (isValidSum(sum, x)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};