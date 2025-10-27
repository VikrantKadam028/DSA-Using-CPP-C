class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int result = 0;

        for (string s : bank) {
            int current = 0;
            for (char c : s) {
                if (c == '1') {
                    current += 1;
                }
            }
            if (current > 0) {
                result += prev * current;
                prev = current;
            }
        }

        return result;
    }
};
