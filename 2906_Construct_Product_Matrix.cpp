class Solution {
public:
    const int MOD = 12345;

    vector<int> getProductSelf(vector<int>& constarr) {
        int n = constarr.size();
        vector<int> result(n);
        vector<long long> prefix(n);
        vector<long long> suffix(n);

        prefix[0] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = (prefix[i - 1] * constarr[i - 1]) % MOD;
        }

        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * constarr[i + 1]) % MOD;
        }

        for (int i = 0; i < n; i++) {
            result[i] = (prefix[i] * suffix[i]) % MOD;
        }

        return result;
    }

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> constructedArr;

        // flatten the 2D grid vec into 1D array
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                constructedArr.push_back(grid[i][j] % MOD);
            }
        }

        vector<int> result = getProductSelf(constructedArr);

        // rebuild matrix , like applying prefix and suffix method , compute the
        // product of self.
        vector<vector<int>> mainResult(rows, vector<int>(cols));

        // and then transform the array into ,breaking it in parts.
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mainResult[i][j] = result[k++];
            }
        }

        return mainResult;
    }
};
