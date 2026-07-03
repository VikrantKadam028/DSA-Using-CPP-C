class Solution {
public:
    void findNse(vector<int>& nse, vector<int>& arr, int n) {
        stack<int> st; // storing indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void findPsee(vector<int>& psee, vector<int>& arr, int n) {
        stack<int> st; // store indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        vector<int> psee(n);

        findNse(nse, arr, n);
        findPsee(psee, arr, n);
        long long total = 0;
        int mod = (int)(1e9 + 7);

        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            total = (total + right * left * 1LL * arr[i]) % mod;
        }
        return total;
    }
};