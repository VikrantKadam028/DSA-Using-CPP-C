class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        stack<double> st;
        st.push(x);

        double ans = 1;

        while (N > 0) {
            if (N % 2 == 1) {
                ans *= st.top();
            }

            double current = st.top();
            st.push(current * current);

            N /= 2;
        }

        return ans;
    }
};