class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indexes;
        int i = 0, j = numbers.size() - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                indexes.push_back(i + 1); 
                indexes.push_back(j + 1);
                return indexes;
            }
            else if (sum < target) {
                i++; 
            }
            else {
                j--; 
            }
        }
        return indexes;
    }
};
