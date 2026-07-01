class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int dist = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        int sum = abs(i - j) + abs(j - k) + abs(k - i);
                        dist = min(dist, sum);
                    }
                }
            }
        }

        return dist == INT_MAX ? -1 : dist;
    }
};