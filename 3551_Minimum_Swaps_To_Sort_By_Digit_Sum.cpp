class Solution {
public:
    int getSum(int n) {
        string result = to_string(n);
        int sum = 0;
        for (char c : result) {
            sum += c - '0';
        }

        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for (int n : nums) {
            arr.push_back({getSum(n), n});
        }

        sort(arr.begin(), arr.end());

        vector<int> newArr;
        for (int i = 0; i < arr.size(); i++) {
            newArr.push_back(arr[i].second);
        }

        map<int, int> Indexes;

        for (int i = 0; i < arr.size(); i++) {
            Indexes[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < newArr.size(); i++) {
            int arrVal = arr[i].second;
            int mapVal = nums[i];

            if (arrVal != mapVal) {
                int j = Indexes[arrVal];

                swap(nums[i], nums[j]);

                Indexes[arrVal] = i;
                Indexes[mapVal] = j;

                swaps++;
            }
        }

        return swaps;
    }
};