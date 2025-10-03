class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> index; 

        for(int i=0; i<nums.size(); i++){
            index[nums[i]] = i;
        }

        for(int i=0; i<operations.size(); i++){
            int oldVal = operations[i][0];
            int newVal = operations[i][1];
            
            int pos = index[oldVal];   
            nums[pos] = newVal;       
            
            index.erase(oldVal);       
            index[newVal] = pos;      
        }

        return nums;
    }
};
