class Solution {
public:
    int minMoves(vector<int>& nums) {
        int largest = 0;
        int sum = 0;

        largest = *max_element(nums.begin(), nums.end());

        for(int n: nums){
            if(n!= largest){
                sum += (largest - n);
            }
        }

        return sum;
    }
};