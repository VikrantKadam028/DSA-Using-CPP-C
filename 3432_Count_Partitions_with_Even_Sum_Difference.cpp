class Solution {
public:
    int getSum(vector<int>& v) {
        int sum = 0;
        for (int x : v) sum += x;
        return sum;
    }

    int countPartitions(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {  
            vector<int> left(nums.begin(), nums.begin() + i + 1);
            vector<int> right(nums.begin() + i + 1, nums.end());

            int diff = getSum(left) - getSum(right);

            if (diff % 2 == 0)
                count++;
        }

        return count;
    }
};
