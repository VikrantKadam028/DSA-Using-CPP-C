class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int x = 0, y = 0;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> temp = grid[i];

            for (int n : temp) {
                ans.push_back(n);
            }
        }

        // sort(ans.begin(), ans.end());

        int n = ans.size();
        vector<int> hash(n+1, 0);
        for (int i = 0; i < ans.size(); i++) {
            hash[ans[i]]++;
        }

        for(int i = 1;i <= n;i++) {
            if (hash[i] == 2) {
                x = i;
            } else if (hash[i] == 0) {
                y = i;
            }
        }

        return {x, y};
    }
};