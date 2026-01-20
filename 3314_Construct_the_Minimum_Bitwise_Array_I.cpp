class Solution {
public:
    //just need to check if (x | x+1) == nums[i], if yes then push else push -1.
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int best = -1;

            int n = nums[i];
            // let the x go from 0 to n;
            for (int x = 0; x <= n; x++) {
                if ((x | x + 1) == n) {
                    best = x;
                    break;
                }
            }
            ans.push_back(best);
        }
        return ans;
    }
};
