class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int leftsum = 0, rightsum = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < k; i++) {
            leftsum += cardPoints[i];
        }

        maxi = leftsum;

        int ridx = n - 1;
        for (int i = k-1; i >= 0; i--) {
            leftsum -= cardPoints[i];
            rightsum += cardPoints[ridx];
            ridx--;
            maxi = max(maxi, leftsum + rightsum);
        }
        return maxi;
    }
};