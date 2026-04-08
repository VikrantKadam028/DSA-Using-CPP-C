class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];
            int nextGreater = -1;
            bool found = false;

            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == num) {
                    found = true;
                }
                else if (found && nums2[j] > num) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            result.push_back(nextGreater);
        }

        return result;
    }
};