class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int curr = 0;

        for(int bit : nums){
            curr = (curr * 2 + bit) % 5;
            result.push_back(curr == 0);
        }
        return result;
    }
};
