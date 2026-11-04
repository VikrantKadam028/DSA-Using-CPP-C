class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;

        //largest, 2nd largest
        long long LH_cnt = 0;
        long long HL_cnt = 0;
        long long largest = *max_element(nums.begin(), nums.end());
        long long Ssmallest = 0;
        sort(nums.begin(), nums.end());
        Ssmallest = nums[nums.size() - 2];

        for (int i = 0; i < nums.size(); i++) {
            LH_cnt += abs(nums[i] - largest);
            HL_cnt += abs(nums[i] - Ssmallest);
        }

        // smallest, 2nd smallest
        long long SL_cnt = 0;
        long long SS_cnt = 0;

        sort(nums.begin(), nums.end());
        long long SL = nums[0];
        long long SS = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != SL) {
                SS = nums[i];
                break;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            SL_cnt += abs(nums[i] - SL);
            SS_cnt += abs(nums[i] - SS);
        }

        // take median
        long long median = -1;

        long long m_cnt = 0;

        median = nums[nums.size() / 2];

        for (int i = 0; i < nums.size(); i++) {
            m_cnt += abs(nums[i] - median);
        }

        long long n1 = min(LH_cnt, HL_cnt);
        long long n2 = min(SL_cnt, SS_cnt);
        return min({n1, n2, m_cnt});
    }
};