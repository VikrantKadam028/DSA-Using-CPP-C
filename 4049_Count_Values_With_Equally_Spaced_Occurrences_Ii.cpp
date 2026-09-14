class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> EleCnt;
        unordered_map<int, vector<int>> OccIndex;

        for (int n : nums) {
            EleCnt[n]++;
        }

        int idx = 0;
        for (int n : nums) {
            OccIndex[n].push_back(idx);
            idx++;
        }

        vector<int> threes;
        for (auto& it : EleCnt) {
            if (it.second >= 3) {
                threes.push_back(it.first);
            }
        }

        set<int> st;
        for (int i = 0; i < threes.size(); i++) {
            int n = threes[i];
            vector<int> temp = OccIndex[n];

            int dist = abs(temp[0] - temp[1]);
            bool isOk = true;
            for (int i = 2; i <temp.size(); i++) {
                if ((temp[i] - temp[i - 1]) != dist) {
                    isOk = false;
                    break;
                }
            }

            if (isOk) {
                st.insert(n);
            }
        }

        return st.size();
    }
};