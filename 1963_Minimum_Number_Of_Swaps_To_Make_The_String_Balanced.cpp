class Solution {
public:
    //1. Remove the [].
    //2. count the '['
    //3. Return the count+1/2.
    
    bool isMatch(char open, char close) { return open == '[' && close == ']'; }
    int minSwaps(string s) {
        stack<int> st;

        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (!st.empty() && isMatch(st.top(), s[i])) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        int cnt = 0;
        while (!st.empty()) {
            if (st.top() == '[')
                cnt++;
            st.pop();
        }
        return (cnt + 1) / 2;
    }
};