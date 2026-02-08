class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        vector<long long> result;

        for (int x : nums) {
            long long cur = x;

            while (!st.empty() && st.top() == cur) {
                cur = st.top() + cur;  
                st.pop();
            }

            st.push(cur);
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
