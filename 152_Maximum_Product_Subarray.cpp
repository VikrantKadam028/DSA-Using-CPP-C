class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            maxi = max(maxi, max(prefix, suffix));
        }

        return maxi;

        // int maxP = INT_MIN;
        // int maxS = INT_MIN;

        // int prod = 1;

        // // prefix sum
        // for (int i = 0; i < nums.size(); i++) {

        //     prod *= nums[i];
        //     maxP = max(prod, maxP);

        //     if (nums[i] == 0) {
        //         prod = 1;
        //     }
        // }

        // prod = 1;

        // // suffix sum
        // for (int i = nums.size() - 1; i >= 0; i--) {

        //     prod *= nums[i];
        //     maxS = max(prod, maxS);

        //     if (nums[i] == 0) {
        //         prod = 1;
        //     }
        // }

        // return max(maxP, maxS);
    }
};