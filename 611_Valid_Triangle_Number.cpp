class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //BRUTE-FORCE
        // int count = 0;
        // sort(nums.begin(), nums.end());
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             if(nums[i] + nums[j] > nums[k]){
        //                 count++;
        //             }
        //         }
        //     }
        // }
        // return count;

        int n = nums.size();
        if (n < 3)
            return 0;

        sort(nums.begin(), nums.end());
        int count = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0;
            int j = k - 1;

            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += (j - i); 
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};
