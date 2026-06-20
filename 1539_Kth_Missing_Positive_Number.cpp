class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missings;

        int curr = 1;
        while (missings.size() < k) {
            bool isPresent = false;
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] == curr) {
                    isPresent = true;
                }
            }

            if (isPresent == false) {
                missings.push_back(curr);
            }
            curr++;
        }

        return missings[k - 1];
    }
};