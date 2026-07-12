class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        
        int n = arr.size();
        vector<int> result;
        vector<int> copy = arr;

        sort(copy.begin(), copy.end());

        int smallest = 1;

        unordered_map<int, int> copied;

        for (int i = 0; i < copy.size() - 1; i++) {
            int num = copy[i];
            copied[num] = smallest;
            if (copy[i + 1] != copy[i]) {
                smallest++;
            }
        }
        copied[copy[copy.size() - 1]] = smallest;

        for (int i = 0; i < arr.size(); i++) {
            result.push_back(copied[arr[i]]);
        }
        return result;
    }
};