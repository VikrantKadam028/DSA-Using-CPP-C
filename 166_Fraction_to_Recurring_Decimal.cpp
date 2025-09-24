class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string result;
        if ((long long)numerator * (long long)denominator < 0) {
            result += "-";
        }

        long long absNum = llabs((long long)numerator);
        long long absDen = llabs((long long)denominator);

        long long integerDiv = absNum / absDen;
        result += to_string(integerDiv);

        long long remain = absNum % absDen;
        if (remain == 0) return result; 

        result += ".";
        unordered_map<long long, int> mp;

        while (remain != 0) {
            if (mp.count(remain)) {
                result.insert(mp[remain], "(");
                result += ")";
                break;
            }

            mp[remain] = result.size();
            remain *= 10;
            long long digit = remain / absDen;
            result += to_string(digit);
            remain %= absDen;
        }

        return result;
    }
};
