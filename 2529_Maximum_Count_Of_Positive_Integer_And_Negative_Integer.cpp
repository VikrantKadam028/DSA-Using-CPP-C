class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        int zeros = 0;

        for(int n : nums){
            if(n == 0) {
                zeros++;
            }
            if(n>0){
                pos++;
            }
        }

        int n = nums.size() - zeros;

        neg = n - pos;

        return max(pos, neg);
    }
};