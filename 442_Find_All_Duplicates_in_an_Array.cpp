class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int idx = abs(nums[i]) - 1;  
            if(nums[idx] < 0){
                res.push_back(abs(nums[i])); 
            } else {
                nums[idx] = -nums[idx];   
            }
        }
        return res;
    }
};

//BRUTE - FORCE
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         unordered_map<int,int> freq;
//         vector<int> twice;
//         for(int num : nums){
//             freq[num]++;
//         }

//         for(auto it : freq){
//             if(it.second == 2){
//                 twice.push_back(it.first);
//             }
//         }
//     return twice;
//     }
// };

