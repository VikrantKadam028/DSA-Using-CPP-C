class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        set<pair<int, int>> st;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 1) {
                    // check row i
                    for (int k = 0; k < col; k++) {
                        if (k == j)
                            continue;
                        if (grid[i][k] == 1) {
                            st.insert({i, k});
                        }
                    }

                    // check col j
                    for (int l = 0; l < row; l++) {
                        if (l == i)
                            continue;

                        if (grid[l][j] == 1) {
                            st.insert({l, j});
                        }
                    }
                }
            }
        }

        return st.size();
    }
};