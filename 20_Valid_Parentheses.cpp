class Solution {
public:
    bool isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') || (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty())
                    return false; 
                char top = st.top();
                st.pop();
                if (!isMatchingPair(top, ch))
                    return false;
            }
        }

        return st.empty(); 
    }
};
