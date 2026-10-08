class Solution {
public:
    bool isMatching(char open, char close) {
        return open == '(' && close == ')';
    }

    string removeOuterParentheses(string s) {
        stack<pair<char, int>> st;
        string result = "";

        for (int i = 0; i < s.length(); i++) {

            if (!st.empty() && isMatching(st.top().first, s[i])) {

                int starting = st.top().second + 1;
                int ending = i - 1;

                st.pop();

                if (st.empty()) {
                    for (int j = starting; j <= ending; j++) {
                        result += s[j];
                    }
                }

            } else {
                st.push({s[i], i});
            }
        }

        return result;
    }
};