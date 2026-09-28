class Solution {
public:
    bool isMatchingPair(char open, char close) {
        return open == '(' && close == ')';
    }

    int maxDepth(string s) {
        stack<char> st;
        int maxi = -1;
        for (char c : s) {
            if (c == ')') {
                if (isMatchingPair(st.top(), c)) {
                    st.pop();
                }
            } else if (c == '(') {
                st.push(c);
            }
            maxi = max((int)st.size(), maxi);
        }

        return maxi;
    }
};