class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long fixed = nums[0];
        int m = k - 1; 
        long long current_window_sum = 0;
        
        multiset<int> low, high;

        auto balance = [&]() {
            while (low.size() < m && !high.empty()) {
                int val = *high.begin();
                current_window_sum += val;
                low.insert(val);
                high.erase(high.begin());
            }
            while (low.size() > m) {
                int val = *low.rbegin();
                current_window_sum -= val;
                high.insert(val);
                low.erase(prev(low.end()));
            }
            if (!low.empty() && !high.empty() && *low.rbegin() > *high.begin()) {
                int l_val = *low.rbegin();
                int h_val = *high.begin();
                current_window_sum = current_window_sum - l_val + h_val;
                low.erase(prev(low.end()));
                high.erase(high.begin());
                low.insert(h_val);
                high.insert(l_val);
            }
        };

        for (int i = 1; i <= dist + 1 && i < n; i++) {
            high.insert(nums[i]);
        }
        balance();
        
        long long ans = fixed + current_window_sum;

        for (int start = 2; start <= n - 1; start++) {
            int out = nums[start - 1];
            auto it = low.find(out);
            if (it != low.end()) {
                current_window_sum -= out;
                low.erase(it);
            } else {
                auto it_high = high.find(out);
                if (it_high != high.end()) high.erase(it_high);
            }

            if (start + dist < n) {
                high.insert(nums[start + dist]);
            }
            
            balance();
            if (low.size() == m) {
                ans = min(ans, fixed + current_window_sum);
            }

            if (start + dist >= n - 1 && n - 1 - start < 0) break;
        }

        return ans;
    }
};

// class Solution {
// public:
//     long long minimumCost(vector<int>& nums, int k, int dist) {

//         int n = nums.size();
//         long long fixed = nums[0];

//         int windowSize = dist + 1;
//         int count = n - 1;
//         int windows = count - windowSize + 1;

//         if (k - 1 > windowSize || windows <= 0)
//             return -1;

//         long long ans = LLONG_MAX;

//         vector<int> temp(windowSize);
//         for (int start = 1; start <= count - windowSize + 1; start++) {

//             for (int j = 0; j < windowSize; j++) {
//                 temp[j] = nums[start + j];
//             }
//             nth_element(temp.begin(), temp.begin() + (k - 1), temp.end());

//             long long sum = fixed;
//             for (int i = 0; i < k - 1; i++) {
//                 sum += temp[i];
//             }

//             ans = min(ans, sum);
//         }

//         return ans;
//     }
// };
