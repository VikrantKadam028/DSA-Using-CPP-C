class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();    // no. of rows
        int m = matrix[0].size(); // no. of cols

        // First row     → matrix[0][j] → j traverses
        // First column  → matrix[i][0] → i traverses

        //represents the mapper for the 1st row.
        int col0 = 1;

        // Create the markers using 1st row & 1st column.
        // Mark which rows and columns need to become 0.
        for (int i = 0; i < n; i++) {

            // If any element in the 1st column is 0,
            // the entire 1st column must become 0.
            if (matrix[i][0] == 0)
                col0 = 0;

            // Start from j = 1 because j = 0 (1st column)
            // is handled separately using col0.
            for (int j = 1; j < m; j++) {

                if (matrix[i][j] == 0) {

                    matrix[i][0] = 0;

                    matrix[0][j] = 0;
                }
            }
        }

        // Now set the remaining matrix elements to 0
        // (excluding the 1st row and 1st column).
        for (int i = 1; i < n; i++) {

            for (int j = 1; j < m; j++) {

                if (matrix[i][0] == 0 ||
                    matrix[0][j] == 0) {

                    matrix[i][j] = 0;
                }
            }
        }

        // Solve the 1st row.
        // If matrix[0][0] is 0, it means the entire
        // 1st row should become 0.
        if (matrix[0][0] == 0) {

            for (int j = 0; j < m; j++) {

                matrix[0][j] = 0;
            }
        }

        // Solve the 1st column.
        // If col0 became 0 during traversal,
        // the entire 1st column should become 0.
        if (col0 == 0) {

            for (int i = 0; i < n; i++) {

                matrix[i][0] = 0;
            }
        }
    }
};