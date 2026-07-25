class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);

        if (str.length() == 1) {
            return n;
        }

        int size = str.length();
        sort(str.begin(), str.end());
        return (str[size - 1] - '0') * (str[size - 2] - '0');
    }
};