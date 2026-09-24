class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            string str = to_string(nums[i]);
            if(str.length() > 1){
                int sum = 0;
                for(char c : str){
                    sum += c - '0';
                }

                if(sum == i){
                    mini = min(mini,i);
                }
            }else {
                if(nums[i] == i && str.length() == 1){
                    mini = min(mini,i);
                }
            }
        }
        return mini == INT_MAX? -1 : mini;
    }
};