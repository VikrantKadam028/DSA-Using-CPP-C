class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (int i = 0; i < operations.size(); i++) {

            if (operations[i] == "+") {
                int a = st.top(); st.pop();
                int b = st.top();
                int sum = a + b;
                st.push(a);
                st.push(sum);

            } else if (operations[i] == "D") {
                st.push(2 * st.top());

            } else if (operations[i] == "C") {
                st.pop();

            } else {
                st.push(stoi(operations[i]));
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
