class Solution {
public:
    // this problem states to find the longest substr with '()()' without any kind of break like '('.

    bool isMatchingPair(char open, char close) {
        return open == '(' && close == ')';
    }

    int longestValidParentheses(string s) {
        stack<int> st;
        int lastInvalid = -1;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            // push if got (.
            if (s[i] == '(') {
                st.push(i);
                // if got ) then check if ( exist on stack top, if yes POP babyy.
            } else if (s[i] == ')') {
                if (!st.empty() && isMatchingPair(s[st.top()], s[i])) {
                    st.pop();

                    //check each time to evaluate the max length of continous substring.
                    if (st.empty()) {
                        ans = max(ans, i - lastInvalid);
                    } else {
                        ans = max(ans, i - st.top());
                    }
                } else {
                    lastInvalid = i;
                }
            }
        }

        return ans;
    }
};
