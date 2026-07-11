class StockSpanner {
private:
    stack<pair<int, int>> st;
    int idx = -1;
    int ans;

public:
    StockSpanner() {
        idx = -1;
        ans = 0;
    }

    int next(int price) {

        idx = idx + 1;

        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        ans = idx - (st.empty() ? -1 : st.top().second);
        st.push({price, idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 /* BRUTE
class StockSpanner {
private:
    vector<int> result;
    int cnt;

public:
    StockSpanner() { cnt = 0; }

    int next(int price) {
        cnt = 0;
        if (result.size() == 0) {
            result.push_back(price);
            return 1;
        }

        for (int i = result.size() - 1; i >= 0; i--) {
            if (result[i] > price) {
                break;
            } else {
                cnt++;
            }
        }
        result.push_back(price);
        return cnt + 1;
    }
};
 */