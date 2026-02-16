class Solution {
public:
    int reverseBits(int n) {
        bitset<32> b(n);
        bitset<32> r;

        for (int i = 0; i < 32; i++) {
            r[i] = b[31 - i];
        }

        return (int)r.to_ulong();
    }
};
