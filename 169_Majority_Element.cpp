class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counter;

        for(int num: nums){
            counter[num]++;
        }

        int maxKey = 0, maxValue = 0;
        for(auto it:counter){
            if(it.second > maxValue){
                maxValue = it.second;
                maxKey = it.first;
            }
        }
        return maxKey;
    }
};
