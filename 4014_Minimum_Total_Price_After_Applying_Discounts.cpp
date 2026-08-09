class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        int n = prices.size();
        vector<int> hash(n, 0);

        reverse(prices.begin(), prices.end());
        reverse(discounts.begin(), discounts.end());

        double result = 0;

        int mini = min(discounts.size(), prices.size());

        for (int i = 0; i < mini; i++) {
            double discount = (prices[i] * (100 - discounts[i])) / 100.0;

            result += discount;
            hash[i] = 1;
        }

        // remaining
        for (int i = 0; i < prices.size(); i++) {
            if (hash[i] == 0) {
                result += prices[i];
            }
        }
        return result;
    }
};