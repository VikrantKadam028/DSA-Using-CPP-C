class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int total = rows * cols;

        k = k % total;
        if (k == 0)
            return grid;

        vector<vector<int>> temp(rows, vector<int>(cols));
        while (k > 0) {
            temp = grid;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {

                    if (j != cols - 1) {
                        temp[i][j + 1] = grid[i][j];
                    } else if (i != rows - 1) {
                        temp[i + 1][0] = grid[i][j];
                    } else if (j == cols - 1 && i == rows - 1) {
                        temp[0][0] = grid[i][j];
                    }
                }
            }
            grid = temp;
            k--;
        }
        return temp;
    }
};