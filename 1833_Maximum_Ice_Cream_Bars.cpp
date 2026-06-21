class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
         sort(costs.begin(), costs.end());
        int sum = 0;
        int c = coins;
        if(c < costs[0]){
            return 0;
        }

        int cnt = 0;
        for(int i=0;i<costs.size();i++){
            if(c >= costs[i] ){
                sum += costs[i];
                c = c - costs[i];
                cnt++;
            }else {
            break;
        }
        }

        return cnt;
    }
};