class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1,
                                          vector<vector<int>>& items2) {
        unordered_map<int, int> I1;
        unordered_map<int, int> I2;

        vector<vector<int>> ans;

        for (int i = 0; i < items1.size(); i++) {
            int val = items1[i][0];
            int weight = items1[i][1];

            I1[val] = weight;
        }

        for (int i = 0; i < items2.size(); i++) {
            int val = items2[i][0];
            int weight = items2[i][1];

            I2[val] = weight;
        }

        //merge
        for(auto &it : I2){
            I1[it.first] += it.second;
        }

        for(auto &it : I1){
            ans.push_back({it.first, it.second});
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};