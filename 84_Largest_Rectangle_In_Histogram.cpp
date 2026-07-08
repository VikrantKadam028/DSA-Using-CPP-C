class Solution {
public:
    void findNse(vector<int>& nse, vector<int> arr, int n) {
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void findPse(vector<int>& pse, vector<int> arr, int n) {
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxi = INT_MIN;
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);

        findNse(nse, heights, n);
        findPse(pse, heights, n);

        for (int i = 0; i < heights.size(); i++) {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxi;
    }
};