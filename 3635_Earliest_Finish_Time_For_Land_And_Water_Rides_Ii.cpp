class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        // Case 1: Land then Water
        int minLandFinish = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
        }

        int waterFinishTime = INT_MAX;
        for (int j = 0; j < waterStartTime.size(); j++) {
            int waterStart = max(minLandFinish, waterStartTime[j]);
            waterFinishTime = min(waterFinishTime, waterStart + waterDuration[j]);
        }

        // Case 2: Water then Land
        int minWaterFinish = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) {
            minWaterFinish = min(minWaterFinish, waterStartTime[i] + waterDuration[i]);
        }

        int landFinishTime = INT_MAX;
        for (int j = 0; j < landStartTime.size(); j++) {
            int landStart = max(minWaterFinish, landStartTime[j]);
            landFinishTime = min(landFinishTime, landStart + landDuration[j]);
        }

        return min(waterFinishTime, landFinishTime);
    }
};