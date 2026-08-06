class Solution {
public:
    int getProduct(int n) {
        string result = to_string(n);

        long long product = 1;
        for (int i = 0; i < result.length(); i++) {
            int no = result[i] - '0';
            product *= no;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        int smallest = 0;
        int idx = n;
        int product = 0;
        while (true) {
            product = getProduct(idx);

            if (product % t == 0) {
                return idx;
            }
            idx++;
        }
        return smallest;
    }
};