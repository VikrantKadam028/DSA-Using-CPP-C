class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // OPTIMAL
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            if (i < n) {
                nge[i] = st.empty() ? -1 : st.top();
            }

            st.push(nums[i % n]);
        }

        return nge;

        // BRUTE
        //  int n = nums.size();
        //  vector<int> nge(n, -1);
        //  int idx = -1;

        // for (int i = 0; i < nums.size(); i++) {
        //     bool got = false;
        //     for (int j = i + 1; j <= i + n - 1; j++) {
        //         idx = j % n;

        //         if (nums[idx] > nums[i]) {
        //             nge[i] = nums[idx];
        //             got = true;
        //             break;
        //         }
        //     }

        //     if (!got)
        //         nge[i] = -1;
        // }

        // return nge;
    }
};