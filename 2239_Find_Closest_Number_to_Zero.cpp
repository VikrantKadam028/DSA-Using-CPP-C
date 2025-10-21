class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        vector<int> result;
        int closest = 0;
        closest = nums[0];
        for (int n : nums) {
            if (abs(n) < abs(closest)) {
                closest = n;
            } else if (abs(n) == abs(closest) && n > closest) {
                closest = n;
            }
        }
        return closest;
    }
};
