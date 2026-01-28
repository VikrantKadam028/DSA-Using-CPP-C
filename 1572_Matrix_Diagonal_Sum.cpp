class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;

        int rows = mat.size();

        for (int i = 0; i < rows; i++) {
            sum += mat[i][i];
            sum += mat[i][rows - i - 1];
        }

        if (rows % 2 != 0) {
            sum -= mat[rows / 2][rows / 2];
        }
        return sum;
    }
};
