class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        if (nums.size() < 2) {
            return nums[0] == 0? 0 : 1;
        }

        bool isAllZero = true;
        int totalXOR = 0;

        for (int n : nums) {
            totalXOR ^= n;

            if(n != 0){
                isAllZero = false;
            }
        }

        if(isAllZero){
            return 0;
        }

        if (totalXOR != 0) {
            return nums.size();
        }

        for (int i = 0; i < nums.size(); i++) {
            if (totalXOR != 0) {
                return nums.size()- 1;
            } else {
                totalXOR ^= nums[i];
            }
        }

        return 0;
    }
};