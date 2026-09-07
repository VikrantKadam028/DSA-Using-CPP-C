class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int firstBreak = -1;

        int l = -1;
        int r = nums.size() - 1;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i + 1] < nums[i]){
                l = i;
                break;
            }
        }
        if(l == -1) return 0;
        for(int i=nums.size() - 1;i>0;i--){
            if(nums[i - 1] > nums[i]){
                r = i;
                break;
            }
        }

        int mn = nums[l];
        int mx= nums[l];
        for(int i=l;i<=r;i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        while(l > 0 && nums[l - 1]>mn){
            l--;
        }

        while(r < nums.size() - 1 && nums[r + 1] < mx){
            r++;
        }


        return r - l + 1;

    }
};