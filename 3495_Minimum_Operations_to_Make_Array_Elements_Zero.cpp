class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long totalOps = 0;

        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long ops = 0;

            long long power = 1, steps = 1;

            while (power <= r) {
                long long low = power;
                long long high = power * 4 - 1; 
                if (high > r) high = r;

                if (l <= high) {
                    long long start = max(l, low);
                    long long end = high;
                    if (start <= end) {
                        long long cnt = end - start + 1;
                        ops += cnt * steps;
                    }
                }

                power *= 4;
                steps++;
            }

            totalOps += (ops + 1) / 2; 
        }

        return totalOps;
    }
};
