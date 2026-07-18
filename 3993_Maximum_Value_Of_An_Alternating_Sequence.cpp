class Solution {
public:
    long long maximumValue(int n, int s, int m) {\
    if(n == 1) return s;
       long long increase = n / 2;
       long long decrease = increase - 1;

       return s + increase * m - decrease;
    }
};