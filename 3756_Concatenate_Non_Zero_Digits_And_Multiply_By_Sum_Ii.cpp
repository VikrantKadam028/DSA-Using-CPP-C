class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = (int)1e9 + 7;
        int n = s.length();
        vector<int> nums;
        
        // Prefix sum for digit sums
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = (prefixSum[i] + (s[i] - '0')) % mod;
        }
        
        // Prefix count of non-zero digits
        vector<int> prefixNonZero(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixNonZero[i + 1] = prefixNonZero[i] + (s[i] != '0');
        }
        
        // Extract non-zero digits
        string result = "";
        for (char c : s) {
            if (c != '0') {
                result += c;
            }
        }
        
        // Precompute prefix values for the non-zero string
        // value[i] = value of result[0..i-1] as a number modulo mod
        vector<long long> prefixValue(result.length() + 1, 0);
        vector<long long> pow10(result.length() + 1, 1);
        
        for (int i = 0; i < result.length(); i++) {
            prefixValue[i + 1] = (prefixValue[i] * 10 + (result[i] - '0')) % mod;
            pow10[i + 1] = (pow10[i] * 10) % mod;
        }
        
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            int sum = (prefixSum[r + 1] - prefixSum[l] + mod) % mod;
            
            int L = prefixNonZero[l];
            int R = prefixNonZero[r + 1];
            
            if (L == R) {
                nums.push_back(0);
                continue;
            }
            
            // Get value of substring result[L..R-1] in O(1)
            // value = prefixValue[R] - prefixValue[L] * 10^(R-L)
            long long number = (prefixValue[R] - (prefixValue[L] * pow10[R - L]) % mod + mod) % mod;
            
            long long ans = (number * sum) % mod;
            nums.push_back((int)ans);
        }
        return nums;
    }
};