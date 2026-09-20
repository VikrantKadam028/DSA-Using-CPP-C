class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for(int i = 0; i < s.length(); i++)
        {
            int idx = i + 1;
            char ch = s[i];
            int val = 26 - (ch - 'a');

            sum += idx * val;
        }

        return sum;
    }
};