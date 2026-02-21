class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {

        int totalPrime = 0;
        for (int i = left; i <= right; i++) {
            int Ones = 0;
            string bits = bitset<32>(i).to_string();

            for (char n : bits) {
                if (n == '1') {
                    Ones++;
                }
            }

            if (isPrime(Ones)) {
                totalPrime++;
            }
        }
        return totalPrime;
    }
};
