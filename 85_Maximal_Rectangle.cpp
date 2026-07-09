class Solution {
public:
    int findLargestRec(vector<int> arr) {
        stack<int> st;
        int elem = 0;
        int nse = 0, pse = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                elem = st.top();
                st.pop();

                nse = i;
                pse = st.empty() ? -1 : st.top();

                maxi = max(maxi, arr[elem] * (nse - pse - 1));
            }
            st.push(i);
        }

        // for leftovers
        while (!st.empty()) {
            elem = st.top();
            st.pop();

            nse = arr.size();
            pse = st.empty() ? -1 : st.top();

            maxi = max(maxi, arr[elem] * (nse - pse - 1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> prefixSum(row, vector<int>(col, 0));

        for (int j = 0; j < col; j++) {
            int sum = 0;

            for (int i = 0; i < row; i++) {
                sum += matrix[i][j] - '0';

                if (matrix[i][j] == '0') {
                    sum = 0;
                }

                prefixSum[i][j] = sum;
            }
        }

        int maxArea = INT_MIN;

        for (int i = 0; i < prefixSum.size(); i++) {
            maxArea = max(maxArea, findLargestRec(prefixSum[i]));
        }

        return maxArea;
    }
};