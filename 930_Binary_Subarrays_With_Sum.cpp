class Solution {
public:
    int getGoal(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;

        int l = 0, r = 0;
        int sum = 0, cnt = 0;

        while (r < nums.size()) {
            sum += nums[r];

            while (sum > goal && l < nums.size()) {
                sum -= nums[l];
                l++;
            }

            int len = r - l + 1;
            cnt += len;

            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return getGoal(nums, goal) - getGoal(nums, goal - 1);
    }
};

//Prefix Approach
/*
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
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
*/