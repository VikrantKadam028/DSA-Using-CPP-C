class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for (char c : text) {
            mp[c]++;
        }

        string result = "balloon";
        int cnt = 0;

        while (true) {
            string temp = "";
            bool isPossible = true;

            for (int i = 0; i < result.length(); i++) {
                if (mp[result[i]] > 0) {
                    temp += result[i];
                    mp[result[i]]--;
                } else {
                    isPossible = false;
                    break;
                }
            }

            if (temp == result) {
                cnt++;
            }

            if (!isPossible) {
                break;
            }
        }

        return cnt;
    }
};