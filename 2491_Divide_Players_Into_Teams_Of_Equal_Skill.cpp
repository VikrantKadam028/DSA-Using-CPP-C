class Solution {
public:
    long long dividePlayers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();

        int low = 1; 
        int high = nums.size()-2;
        int requiredPro = nums[0] + nums[n-1];
        long long sum = nums[0] * nums[n-1];

        while(low < high){
            if((nums[low] + nums[high]) != requiredPro){
                return -1;
            }

            sum += nums[low] * nums[high];
            low++;
            high--;
        }

        return sum;
    }
};