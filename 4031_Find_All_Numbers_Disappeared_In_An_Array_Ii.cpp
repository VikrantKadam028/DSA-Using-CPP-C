class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> mpp;

        for (int n : nums) {
            mpp[n]++;
        }

        vector<vector<int>> vec;

        for (int i = lower; i <= upper; i++) {
            result.push_back(i);
        }

        vector<int> temp;
        for (int i = 0; i < result.size(); i++) {

            if (mpp.find(result[i]) != mpp.end()) {

                if (temp.size() == 1) {
                    vec.push_back({temp[0], temp[0]});
                    temp.clear();
                } else if (temp.size() > 2) {
                    sort(temp.begin(), temp.end());
                    vec.push_back({temp[0], temp[temp.size() - 1]});
                    temp.clear();
                } else if (temp.size() == 2) {
                    vec.push_back(temp);
                    temp.clear();
                }
            } else if (mpp.find(result[i]) == mpp.end()) {
                temp.push_back(result[i]);
            }
        }

        if(temp.size() >= 1){
            if (temp.size() == 1) {
            vec.push_back({temp[0], temp[0]});
            temp.clear();
        } else if (temp.size() > 2) {
            sort(temp.begin(), temp.end());
            vec.push_back({temp[0], temp[temp.size() - 1]});
            temp.clear();
        } else if (temp.size() == 2) {
            vec.push_back(temp);
            temp.clear();
        }
        }

        return vec;
    }
};