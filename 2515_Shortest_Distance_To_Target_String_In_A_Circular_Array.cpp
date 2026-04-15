class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int left = -1, right = -1;

        for (int step = 0; step < n; step++) {
            int i = (startIndex + step) % n;
            if (words[i] == target) {
                right = step;
                break;
            }
        }

        for (int step = 0; step < n; step++) {
            int i = (startIndex - step + n) % n;
            if (words[i] == target) {
                left = step;
                break;
            }
        }

        if (left == -1 && right == -1) return -1;
        if (left == -1) return right;
        if (right == -1) return left;

        return min(left, right);
    }
};