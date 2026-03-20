class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int total = 0;
        unordered_map<int, int> freq;

        for (int n : candyType) {
            freq[n]++;
        }

        int unique = freq.size();

        total = candyType.size() / 2;

        return min(unique, total);
    }
};
