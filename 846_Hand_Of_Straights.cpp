class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> mpp;

        for (int n : hand) {
            mpp[n]++;
        }

        sort(hand.begin(), hand.end());

        for (int i = 0; i < hand.size(); i++) {
            int num;
            if(mpp[hand[i]] > 0){
                num = hand[i];
            }else {
                continue;
            }
            int next = num + 1;
            bool isPresent = true;

            vector<int> ans;
            ans.push_back(num);
            

            for (int j = 0; j < groupSize-1; j++) {
                if (mpp.find(next) != mpp.end()) {
                    if (mpp[next] > 0) {
                        ans.push_back(next);
                         next = next + 1;
                    }
                   
                } else {
                    isPresent = false;
                    break;
                }
            }

            if (isPresent && ans.size() == groupSize) {
                for (int n : ans) {
                    mpp[n]--;
                }
            }
        }

        for(auto &it : mpp){
            if(it.second > 0){
                return false;
            }
        }

        return true;
    }
};