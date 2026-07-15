class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // int no = n * 2;
        // int even = 0, odd = 0;

        // for (int i = 0; i < no; i++) {
        //     if (i % 2 == 0) {
        //         even += i;
        //     } else {
        //         odd += i;
        //     }
        // }
        // return gcd(even, odd);
        return gcd(n * (n+1), n * n);
    }
};