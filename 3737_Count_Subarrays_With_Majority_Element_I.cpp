class Solution {
public:
    // Using this func coz me TLE.
    //  int countTarget(int target, vector<int>& temp) {
    //      int cnt = 0;
    //      for (int i = 0; i < temp.size(); i++) {
    //          if (temp[i] == target) {
    //              cnt++;
    //          }
    //      }
    //      return cnt;
    //  }

    // BRUTE FORCE - O(n^2)
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp;
            int elCount = 0;

            for (int j = i; j < nums.size(); j++) {
                temp.push_back(nums[j]);

                if (nums[j] == target)
                    elCount++;

                if (2 * elCount > temp.size()) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};