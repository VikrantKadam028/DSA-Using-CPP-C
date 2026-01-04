class Solution {
public:
    pair<int, int> getDivisorsTotal(int digit) {
        int count = 0;
        int total = 0;

        for (int j = 1; j * j <= digit; j++) {
            if (digit % j == 0) {
                int other = digit / j;

                // count j
                count++;
                total += j;

                // count digit/j if different
                if (other != j) {
                    count++;
                    total += other;
                }

                // early stop
                if (count > 4) {
                    return {count, total};
                }
            }
        }
        return {count, total};
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for (int digit : nums) {
            auto res = getDivisorsTotal(digit);
            if (res.first == 4) {
                sum += res.second;
            }
        }
        return sum;
    }
};


//BRUTE - FORCE
// class Solution {
// public:
//     pair<int, int> getDivisorsTotal(int digit) {
//         int count = 0;
//         int total = 0;
//         for (int j = 1; j * j <= digit; j++) {
//             if (digit % j == 0) {
//                 count++;
//                 total += j;
//             }
//         }
//         return {count, total};
//     }

//     int sumFourDivisors(vector<int>& nums) {
//         int digit = 0;
//         int divisors = 0;
//         int totalCount = 0;
//         int sum = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             digit = nums[i];
//             auto res = getDivisorsTotal(digit);
//             divisors = res.first;
//             totalCount = res.second;

//             if (divisors == 4) {
//                 sum += totalCount;
//             }
//         }
//         return sum;
//     }
// };
