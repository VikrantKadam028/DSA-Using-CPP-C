class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int cnt = 0;

        for (int n : nums) {
            mpp[n]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mpp.find(num) == mpp.end() || mpp[num] <= 0)
                continue;
            mpp[num]--;
            int toFind = k - num;
            bool used = false;

            if (mpp.find(toFind) != mpp.end()) {
                if (mpp[toFind] > 0) {
                    used = true;
                    mpp[toFind]--;
                    cnt++;

                    if (mpp[num] == 0) {
                        mpp.erase(num);
                    }
                    if (mpp[toFind] == 0)
                        mpp.erase(toFind);
                }
            }

            if (!used) {
                mpp[num]++;
            }
        }
        return cnt;
    }
};