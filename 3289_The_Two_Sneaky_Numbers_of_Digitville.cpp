class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int freq[101] = {0};  
        vector<int> result;

        for (int n : nums) {
            freq[n]++;
        }

        for (int i = 0; i <= 100; i++) {
            if (freq[i] == 2)
                result.push_back(i);
        }

        return result;
    }
};
