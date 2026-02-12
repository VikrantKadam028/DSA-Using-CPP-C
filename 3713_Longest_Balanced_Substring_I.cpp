class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int longest = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                bool isBalanced = true;

                int firstFreq = -1;
                for (auto &it : freq) {
                    if (firstFreq == -1) {
                        firstFreq = it.second;  
                    } else if (it.second != firstFreq) {
                        isBalanced = false;
                        break;
                    }
                }

                if (isBalanced) {
                    longest = max(longest, j - i + 1);
                }
            }
        }
        return longest;
    }
};

