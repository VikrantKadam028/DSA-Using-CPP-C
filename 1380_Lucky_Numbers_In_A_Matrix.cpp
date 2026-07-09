class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        unordered_map<int, int> freq;

        for (int i = 0; i < row; i++) {
            int mini = INT_MAX;

            for (int j = 0; j < col; j++) {
                mini = min(mini, matrix[i][j]);
            }
         
            freq[mini]++;
        }

        vector<int> maximums(row);
        for (int j = 0; j < col; j++) {
            int maxi = INT_MIN;

            for (int i = 0; i < row; i++) {
                maxi = max(maxi, matrix[i][j]);
            }
          
            if (freq.find(maxi) != freq.end()) {
                return {maxi};
            }
        }
        return {};
    }
};