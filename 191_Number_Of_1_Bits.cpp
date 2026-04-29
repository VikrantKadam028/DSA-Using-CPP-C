class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> b(n);

        return b.count();
    }
};