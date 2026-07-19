// Explanation:
// we take, freq : To check if the s[i] is already visited or not.
// map : To control the freq of each char in str.
// stack : keeping the stack in monotonic nature (increasing), push if greater
// char , else pop till st.top() > currstr.

// We are iterating through s, then do mpp[s[i]]--, if we have already visited
// that char then skip. then pop the stack will we not maintain the monotonic
// nature of stack (we pop only if we know that we can get this char afterwards
// , like its present somewhere next in the str i.e mpp[s[i]] > 0, else consider
// that str (dont pop)).
// then we push that char into stack, and mark it as visited.
// iterate stack and get result and return rev(result);

//  lexicographically smallest subsequence : suppose there is abc & bca, then as (a < b), So abc is the lexicographically smallest subsequence.

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