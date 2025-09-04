class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distanceXZ = abs(z - x);
        int distanceYZ = abs(z - y);

        if (distanceXZ < distanceYZ) {
            return 1; 
        } else if (distanceYZ < distanceXZ) {
            return 2; 
        }
        return 0; 
    }
};
