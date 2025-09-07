class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result;           
        result.push_back(nums[0]);    
        int k = nums[0];             

        for (int i = 1; i < nums.size(); i++) {
            if (k == nums[i]) {
                continue;           
            } else {
                k = nums[i];
                result.push_back(nums[i]); 
            }
        }

        for (int i = 0; i < result.size(); i++) {
            nums[i] = result[i];
        }

        return result.size();         
    }
};

