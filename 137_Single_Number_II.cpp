class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        int max = 0;
        for(int num: nums){
            freq[num]++;
        }

        for(auto it : freq){
            if(it.second == 1){
                max = it.first;
            }
        }
    return max;
    }
};
