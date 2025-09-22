class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int maxFreq = 0;
        for (auto& p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        int freqCount = 0;
        for (auto& p : freq) {
            if (maxFreq == p.second) {
                freqCount++;
            }
        }
        return freqCount * maxFreq;
    }
};
