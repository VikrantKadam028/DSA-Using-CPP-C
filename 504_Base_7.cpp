class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";

        bool isNeg = num < 0 ? true : false;
        num = abs(num);
        string out = "";
        while (num > 0) {
            int rem = num % 7;
            out += to_string(rem);
            num /= 7;
        }
        reverse(out.begin(), out.end());
        if (isNeg) {
            out = "-" + out;
        }
        return out;
    }
};
