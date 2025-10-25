class Solution {
public:
    int totalMoney(int n) {
        int isMonday = 1;
        int totalMoney = 0;
        int count = 1;
        for (int i = isMonday; i <= n; i++) {
            totalMoney += (isMonday + (count - 1));
            count++;
            if (count == 8) {
                isMonday++;
                count = 1;
            };
        }
        return totalMoney;
    }
};
