class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        unordered_map<char, int> mpp;
        string result = "";
        stack<char> st;

        for (char c : s) {
            mpp[c]++;
        }

        for (int i = 0; i < s.length(); i++) {
            mpp[s[i]]--;
            if (freq[s[i] - 'a'] == 1)
                continue;
            while (!st.empty() && st.top() > s[i] && mpp[st.top()] > 0) {
                char c = st.top();
                freq[c - 'a'] = 0;

                st.pop();
            }
            st.push(s[i]);
            freq[s[i] - 'a'] = 1;
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};