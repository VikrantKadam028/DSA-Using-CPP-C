class Solution {
public:
    bool isMatchPair(char open, char close) {
        return open == '(' && close == ')';
    }
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (!st.empty() && isMatchPair(st.top(), s[i])) {
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }

        return st.size();
    }
};