class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long DestroyCount = 0;
        long long newMass = mass;
        for (int i = 0; i < asteroids.size(); i++) {
            if (newMass >= asteroids[i]) {
                DestroyCount++;
                newMass += asteroids[i];
            } else {
                break;
            }
        }

        if (DestroyCount == asteroids.size()) {
            return true;
        }
        return false;
    }
};