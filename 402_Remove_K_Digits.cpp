class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        stack<int> st;

        // edge case 1 :
        if (k == num.size())
            return "0";

        for (int i = 0; i < num.length(); i++) {
            while (!st.empty() && st.top() > (num[i] - '0') && k > 0) {
                st.pop();
                k--;
            }

            st.push(num[i] - '0');
        }

        // edge case 2 :
        // suppose num = "112", k = 1,then we need a o/p as "11".
        while (k > 0) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            result += to_string(st.top());
            st.pop();
        }

        // edge case 3 :
        // remove zeros of front.
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }

        reverse(result.begin(), result.end());

        return result.empty() ? "0" : result;
    }
};