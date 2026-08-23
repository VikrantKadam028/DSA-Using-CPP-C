class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int mid = n / 2;
        int leftSum = 0;
        int rightSum = 0;
        int leftQuestion = 0;
        int rightQuestion = 0;

        for (int i = 0; i < mid; i++) {
            if (num[i] == '?') {
                leftQuestion++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        for (int i = mid; i < n; i++) {
            if (num[i] == '?') {
                rightQuestion++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        if (2 * (leftSum - rightSum) ==
            9 * (rightQuestion - leftQuestion)) {
            return false;
        }

        return true;
    }
};