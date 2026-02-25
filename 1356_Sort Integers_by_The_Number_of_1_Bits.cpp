class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        string bits = "";

        unordered_map<char, vector<int>> mp;

        // Iteratng each digit and counting no of Ones in there binary repre.
        //  OnesCount : vector nos
        for (int i = 0; i < arr.size(); i++) {
            int OnesCount = 0;
            bits = bitset<32>(arr[i]).to_string();

            for (char c : bits) {
                if (c == '1') {
                    OnesCount++;
                }
            }

            mp[OnesCount].push_back(arr[i]);
        }

        vector<int> result;

        vector<int> keys;
        // sorting all the keys of mp.
        for (auto& it : mp) {
            keys.push_back(it.first);
        }
        sort(keys.begin(), keys.end());

        // fnding vec associated with the particular key soting vector and push
        // each no from vec to result.
        for (int key : keys) {
            auto& v = mp[key];
            sort(v.begin(), v.end());

            for (int x : v) {
                result.push_back(x);
            }
        }
        return result;
    }
};
