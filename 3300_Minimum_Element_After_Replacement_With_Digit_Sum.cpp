class Solution {
public:
    int minElement(vector<int>& nums) {
        string digit = "";
        int sum = 0;
        vector<int> result;
        for(int i= 0;i<nums.size();i++){
            digit = to_string(nums[i]);

            for(char c : digit){
                sum += c - '0';
            } 
            result.push_back(sum);
            sum = 0;
        }

        sort(result.begin(), result.end());
        return result[0];
    }
};