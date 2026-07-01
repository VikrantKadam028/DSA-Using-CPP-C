class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i]) && s[i] != '#') {
                s1.push(s[i]);
            } else if (s[i] == '#') {
                if (!s1.empty())
                    s1.pop();
            }
        }

        for (int i = 0; i < t.length(); i++) {
            if (isalpha(t[i]) && t[i] != '#') {
                s2.push(t[i]);
            } else if (t[i] == '#') {
                if (!s2.empty())
                    s2.pop();
            }
        }

        return s1 == s2;
    }
};