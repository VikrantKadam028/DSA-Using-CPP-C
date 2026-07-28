class Solution {
public:
    string smallestPalindrome(string s) {
        if (s.length() == 1)
            return s;
        map<char, int> mpp;

        // build an freq map (ascending)
        for (char c : s) {
            mpp[c]++;
        }

        string result = "";

        // Build the first half, by taking the half freq of each char.
        for (auto& it : mpp) {
            char ch = it.first;
            int val = it.second / 2;

            mpp[ch] %= 2;
            while (val > 0) {
                result += ch;
                val--;
            }
        }

        string firstHalf = result;

        // if s is even len, the no middle elem
        // if odd - middle exist,so append it.
        char middle;
        if (s.length() % 2 != 0) {
            for (auto& it : mpp) {
                if (it.second == 1) {
                    middle = it.first;
                    break;
                }
            }
            result += middle;
        }

        // rev the firsthalf and append to result;
        string rev = firstHalf;
        reverse(rev.begin(), rev.end());

        result += rev;

        return result;
    }
};