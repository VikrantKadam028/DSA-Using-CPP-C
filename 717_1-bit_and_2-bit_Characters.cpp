class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool isOneBit = false;

        for(int i = 0; i < bits.size(); ) {
            if (bits[i] == 0) {
                isOneBit = true;
                i += 1;
            } 
            else {
                isOneBit = false;
                i += 2;
            }
        }

        return isOneBit;
    }
};
