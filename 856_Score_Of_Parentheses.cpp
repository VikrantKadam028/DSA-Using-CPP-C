class Solution {
public:
    // Just traverse and if we encountered '('then push 0, else if ')' then
    // calculate till we get prev opening bracket and keep adding the top into
    // val and take max(2*val, 1). pop the prev val and push the calculated val.
    int scoreOfParentheses(string s) {
        stack<int> st;
        int cnt = 0;
        for (char c : s) {
            int val = 0;
            if (c == '(') {
                st.push(0);
            } else if (c == ')') {
                while (st.top() != 0) {
                    val += st.top();
                    st.pop();
                }

                val = max(2 * val, 1);
                st.pop();
                st.push(val);
            }
        }

        while (!st.empty()) {
            cnt += st.top();
            st.pop();
        }
        return cnt;
    }
};