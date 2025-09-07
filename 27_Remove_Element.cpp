class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                result.push_back(nums[i]);
            }
        }

        for(int i=0;i<result.size();i++){
            nums[i] = result[i];
        }
    return result.size();
    }
};
