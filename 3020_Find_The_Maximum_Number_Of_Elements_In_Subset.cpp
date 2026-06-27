class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int n : nums) {
            mp[n]++;
        }

        int maxi = INT_MIN;

        for (auto& it : mp) {
            int x = it.first;

            if (x == 1) {
                if (mp[1] % 2 == 0) {
                    maxi = max(maxi, mp[1] - 1);
                } else {
                    maxi = max(maxi, mp[1]);
                }
                continue;
            }

            long long curr = x;
            int len = 1;

            while (mp[curr] > 1) {
                if (curr > 1000000000LL)
                    break;
                long long nxtSqr = curr * curr;

                if (mp.find(nxtSqr) == mp.end()) {
                    break;
                }
                len += 2;
                curr = nxtSqr;
            }

            if (mp[curr] >= 1)
                maxi = max(maxi, len);//center exist
            else
                maxi = max(maxi, len - 1);// center not exist
        }
        return maxi;
    }
};