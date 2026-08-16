class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini = -1;
        int x2 = target[0];
        int y2 = target[1];
        int miniDist = INT_MAX;
        
        for (int i = 0; i < drones.size(); i++) {
            int x1 = drones[i][0];
            int y1 = drones[i][1];

            int range = drones[i][2];

            int dist = abs(x1 - x2) + abs(y1 - y2);

            if (dist <= range) {
                
                if (dist < miniDist) {
                    miniDist = dist;
                    mini = i;
                }else if (dist == miniDist) {
                    mini = min(mini, i);
                }
            }
        }

        return mini;
    }
};