class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
    const int MOD = 1e9 + 7;
    vector<long long> dp(n + 1, 0);  
    dp[1] = 1;  

    for (int day = 1; day <= n; day++) {
        long long sharers = dp[day];
        if (sharers == 0) continue;

        int start = day + delay;
        int end   = day + forget - 1; 

        for (int d = start; d <= min(n, end); d++) {
            dp[d] = (dp[d] + sharers) % MOD;
        }
    }

    long long ans = 0;
    for (int day = n - forget + 1; day <= n; day++) {
        if (day >= 1) ans = (ans + dp[day]) % MOD;
    }
    return ans;
}

};

