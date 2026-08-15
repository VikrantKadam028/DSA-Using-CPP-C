class Solution {
public:

    vector<int> getLeft(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candiesLeft(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candiesLeft[i] = candiesLeft[i - 1] + 1;
            }
        }

        return candiesLeft;
    }

    vector<int> getRight(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candiesRight(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candiesRight[i] = candiesRight[i + 1] + 1;
            }
        }

        return candiesRight;
    }

    int candy(vector<int>& ratings) {

        vector<int> candiesLeft = getLeft(ratings);
        vector<int> candiesRight = getRight(ratings);

        int cnt = 0;

        for (int i = 0; i < ratings.size(); i++) {
            cnt += max(candiesLeft[i], candiesRight[i]);
        }

        return cnt;
    }
};

//didnt work as we dont know the next rating's candies
/* 
int n = ratings.size();

        vector<int> candies(n, 1);

        for (int i = 0; i < ratings.size(); i++) {
            if (i > 0 && i < n - 1) {
                if (ratings[i - 1] < ratings[i]) {
                    candies[i] = candies[i - 1] + 1;
                } else if (ratings[i + 1] < ratings[i]) {
                    candies[i] = candies[i + 1] + 1;
                } else if (ratings[i] > ratings[i - 1] &&
                           ratings[i] > ratings[i + 1]) {
                    candies[i] = max(candies[i - 1], candies[i + 1]) + 1;
                }

            }
            // no prev. have next
            else if (i == 0) {
                if (ratings[i + 1] < ratings[i]) {
                    candies[i] = candies[i + 1] + 1;
                } else {
                    candies[i] = 1;
                }
                // have prev, have next (middle ones)
            } else if (i == n - 1) {
                if (ratings[i - 1] < ratings[i]) {
                    candies[i] = candies[i - 1] + 1;
                } else {
                    candies[i] = 1;
                }
            }
        }

        int cnt = 0;

        for (int n : candies) {
            cnt += n;
        }
        return cnt;
*/