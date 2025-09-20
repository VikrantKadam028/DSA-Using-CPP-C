class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        unordered_map<int, int> freq;

        for (int n : arr1) {
            freq[n]++;
        }

        for (int n : arr2) {
            if (freq.find(n) != freq.end()) {
                int val = freq[n];
                for (int j = 0; j < val; j++)
                    result.push_back(n);
                freq.erase(n);
            }
        }

        vector<int> temp;
        for (auto& p : freq) {
            for (int j = 0; j < p.second; j++)
                temp.push_back(p.first);
        }
        sort(temp.begin(), temp.end());
        result.insert(result.end(), temp.begin(), temp.end());

        return result;
    }
};
