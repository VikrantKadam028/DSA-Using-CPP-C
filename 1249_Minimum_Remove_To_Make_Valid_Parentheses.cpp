class Solution {
public:
    bool isMatch(char open, char close) { return open == '(' && close == ')'; }
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;

        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (!st.empty() && isMatch(st.top().first, s[i])) {
                st.pop();
            } else {
                if (!isalpha(s[i])) {
                    st.push({s[i], i});
                }
            }
        }

        while (!st.empty()) {
            s[st.top().second] = '*'; // erase takes O(n) So, it becomesO(n^2), So mark that char
                     // as '*', and then rebuild string.
            st.pop();
        }

        string result = "";
        for (char c : s) {
            if (c != '*') {
                result += c;
            }
        }
        return result;
    }
};