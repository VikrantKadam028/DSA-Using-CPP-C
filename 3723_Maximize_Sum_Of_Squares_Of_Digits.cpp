class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num < 2 && sum < 9)
            return to_string(sum);
        
        //if sum is -ve or sum cannt be compute by maxi of num then "".
        if(sum < 0 || sum > 9 * num) return "";

        string result = "";

        //here, check if sum <=9 , if yes just add num - 1 zeros at end.
        if (num > 0 && sum <= 9) {
            result += to_string(sum);

            int val = num - 1;
            while (val--) {
                result += '0';
            }
        //if sum > 9, then keep adding and subt 9 and when sum becomes < 9 add that no at end.
        } else {
            int n = num;
            while (n--) {
                if (sum > 9) {
                    result += '9';
                    sum -= 9;
                } else {
                    result += to_string(sum);
                    sum = 0;
                }
            }
        }

        //if my result size < required num size , then add zeors at end.
        if(result.length() < num){
            int size = num - result.length();

            while(size--){
                result += '0';
            }
        }

        return result;
    }
};