class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int LandWater = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            int landFinishTime = landStartTime[i] + landDuration[i];

            for (int j = 0; j < waterStartTime.size(); j++) {
                int waterFinishTime = max(landFinishTime, waterStartTime[j]);
                int finalWater = waterFinishTime + waterDuration[j];
                LandWater = min(LandWater, finalWater);
            }
        }

        int WaterLand = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) {
            int WaterFinishTime = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < landStartTime.size(); j++) {
                int LandFinishTime = max(WaterFinishTime, landStartTime[j]);
                int finalLand = LandFinishTime + landDuration[j];
                WaterLand = min(WaterLand, finalLand);
            }
        }
        return min(LandWater, WaterLand);
    }
};