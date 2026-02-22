class Solution {
public:
    int binaryGap(int n) {
        string bits = bitset<32>(n).to_string();

        int longest = 0;
        int j = 0;

        for (int i = 0; i < bits.length(); i++) {
            if (bits[i] == '1') {
                j = i + 1;

                while (j < bits.length() && bits[j] != '1') {
                    j++;
                }

                if (j < bits.length() && bits[j] == '1') {
                    int distance = j - i;
                    longest = max(longest, distance);
                    i = j - 1;
                }
            }
        }
        return longest;
    }
};
