class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if (n > flowerbed.size())
            return false;

        else if (n == flowerbed.size() && flowerbed[0] == 0 && n == 1)
            return true;
        
        else if(flowerbed.size() == 2){
            if(flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0 && n<= 1) return true; 
        }

        if (flowerbed.size() >= 3 && n < flowerbed.size()) {
            int left = 0;
            int curr = 1;
            int right = 2;

            if (flowerbed[0] == 0 && flowerbed[1] == 0) {
                flowerbed[0] = 1;
                n--;
            }

            while (right < flowerbed.size()) {
                if (flowerbed[left] == 0 && flowerbed[right] == 0 &&
                    flowerbed[curr] == 0) {
                    flowerbed[curr] = 1;
                    n--;
                }
                left++;
                curr++;
                right++;
            }

            if (flowerbed[flowerbed.size() - 1] == 0 &&
                flowerbed[flowerbed.size() - 2] == 0) {
                flowerbed[flowerbed.size() - 1] = 1;
                n--;
            }
        }

        return n <= 0;
    }
};