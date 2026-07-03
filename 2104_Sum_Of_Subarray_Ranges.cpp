class Solution {
public:
    void findNse(vector<int>& nse, vector<int>& nums, int n) {
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void findPsee(vector<int>& psee, vector<int>& nums, int n) {
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void findNge(vector<int>& nge, vector<int>& nums, int n) {
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void findPgee(vector<int>& pgee, vector<int>& nums, int n) {
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    long long subArrayRanges(vector<int>& nums) {
        long long mini = 0;
        long long maxi = 0;
        int n = nums.size();
      
        vector<int> psee(n);
        vector<int> nse(n);
        findNse(nse, nums, n);
        findPsee(psee, nums, n);

        // mini
        for (int i = 0; i < nums.size(); i++) {
            // NSE, PSEE
            int left = i - psee[i];
            int right = nse[i] - i;

            mini = mini + right * left * 1LL * nums[i];
        }

        vector<int> pgee(n);
        vector<int> nge(n);
        findNge(nge, nums, n);
        findPgee(pgee, nums, n);
        // maxi
        for (int i = 0; i < nums.size(); i++) {
            // NGE, PGEE
            int left = i - pgee[i];
            int right = nge[i] - i;

            maxi = maxi + right * left * 1LL * nums[i];
        }
        return maxi - mini;
    }
};