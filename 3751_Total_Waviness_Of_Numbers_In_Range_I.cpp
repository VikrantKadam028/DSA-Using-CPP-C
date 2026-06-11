class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;

        for (int i = num1; i <= num2; i++) {
            string digit = to_string(i);
            int waviness = 0;
            for (int j = 1; j < digit.length() - 1; j++) {
                int prev = digit[j - 1] - '0';
                int curr = digit[j] - '0';
                int next = digit[j + 1] - '0';

                if (prev < curr && curr > next) {
                    waviness++;
                }

                if(prev > curr && next > curr){
                    waviness++;
                }
            }

            total += waviness;
        }

        return total;
    }
};