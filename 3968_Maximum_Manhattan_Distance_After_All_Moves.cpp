class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0;
        int cnt = 0;

        for (char c : moves) {
            if (c == 'U') y++;
            else if (c == 'D') y--;
            else if (c == 'L') x--;
            else if (c == 'R') x++;
            else if (c == '_') cnt++;
        }

        return abs(x) + abs(y) + cnt;
    }
};