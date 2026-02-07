class Solution {
public:
    int minimumDeletions(string s) {
        reverse(s.begin(), s.end());
        stack<char> st;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            char word = s[i];

            if (!st.empty() && s[i] > st.top()) {
                st.pop();
                count++;
            } else {
                st.push(s[i]);
            }
        }

        return count;
    }
};
