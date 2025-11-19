class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool changed = true;

        while (changed) {
            changed = false;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == original) {
                    original = original * 2;
                    changed = true;
                    break;  
                }
            }
        }
        return original;
    }
};
