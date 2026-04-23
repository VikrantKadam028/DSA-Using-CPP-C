class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int n : nums){
            freq[n]++;
        }

        vector<int> result;
        for(auto it : freq){
            result.push_back(it.first);
        }

        sort(result.begin(), result.end(), greater<int>());

        if(result.size() < 3){
            return result[0];
        }

        return result[2]; 
    }
};