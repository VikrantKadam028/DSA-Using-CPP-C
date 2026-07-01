class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        if (cost.size() == 2)
            return cost[0] + cost[1];

        if (cost.size() == 1)
            return cost[0];
        int n = cost.size();
        int idx = n - 1;
        int sum = 0;

        while(n >= 3){
            
                int c1 = cost[idx];
                int c2 = cost[idx - 1];

                int free = cost[idx - 2];

                if (free <= min(c1, c2))
                    sum += c1 + c2;
                idx -= 3;
                n -= 3;
            
        }

        while(idx >= 0) {
            sum += cost[idx];
            idx--;
        }
        return sum;
    }
};