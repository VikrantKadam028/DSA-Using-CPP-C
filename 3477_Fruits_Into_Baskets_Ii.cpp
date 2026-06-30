class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;

        for (int i = 0; i < fruits.size(); i++) {
            int fruit = fruits[i];
            for (int j = 0; j < baskets.size(); j++) {

                if (baskets[j] >= fruit) {
                    baskets[j] = -1;
                    break;
                }
            }
        }

        for (int n : baskets) {
            if (n != -1)
                unplaced += 1;
        }
        return unplaced;
    }
};