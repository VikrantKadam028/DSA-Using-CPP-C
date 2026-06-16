class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        int cnt = 0;

        map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int rem = prefixSum - k;

            if (mp.find(rem) != mp.end()) {
                cnt += mp[rem];
            }

            mp[prefixSum] += 1;
        }
        return cnt;
    }
};

// BRUTE
//  int count = 0;

// for(int i=0;i<nums.size();i++){
//     int sum =0;
//     for(int j=i;j<nums.size();j++){
//         sum += nums[j];

//         if(sum == k){
//             count++;
//         }
//     }
// }