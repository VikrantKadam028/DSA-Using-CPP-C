class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        long long total = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                total += grid[i][j]; 
            }
        }

        long long horizontal = 0;
        for (int i = 0; i < rows - 1; i++) {
            for (int j = 0; j < cols; j++) {
                horizontal += grid[i][j];
            }

            if (horizontal * 2 == total) {
                return true;
            }
        }

        long long vertical = 0;
        for (int i = 0; i < cols - 1; i++) {
            for (int j = 0; j < rows; j++) {
                vertical += grid[j][i];   
            }

            if (vertical * 2 == total) {
                return true;
            }
        }

        return false;
    }
};
