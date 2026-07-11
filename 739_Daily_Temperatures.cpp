class Solution {
public:
    void findNGE(vector<int>& nge, vector<int>& arr, int n) {
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        
        vector<int> nge(n);
        findNGE(nge, temperatures, n);

        for (int i = 0; i < n; i++) {
            if (nge[i] != 0) {
                result[i] = nge[i] - i;
            } else {
                result[i] = 0;
            }
        }
        return result;
    }
};