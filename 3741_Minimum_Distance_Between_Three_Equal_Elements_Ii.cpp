class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if (nums.size() < 3)
            return -1;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int dist = INT_MAX;
        for (auto& it : mp) {
            vector<int>& temp = it.second;

            if (temp.size() == 3) {
                int sum = abs(temp[0] - temp[1]) + abs(temp[1] - temp[2]) +
                          abs(temp[0] - temp[2]);
                dist = min(dist, sum);
            } else if (temp.size() > 3) {
                for (int i = 0; i < temp.size() - 2; i++) {
                    int j = i + 1;
                    int k = j + 1;

                    int sum = abs(temp[i] - temp[j]) + abs(temp[j] - temp[k]) +
                              abs(temp[k] - temp[i]);
                    dist = min(dist, sum);
                }
            }
        }

        return dist == INT_MAX ? -1 : dist;
    }
};