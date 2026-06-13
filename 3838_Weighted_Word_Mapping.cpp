class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            int sum = 0;
            for (char c : str) {
                sum += weights[c - 'a'];
            }
            int mod = sum % 26;
            result += char('a' + (26 - mod) - 1);
        }

        return result;
    }
};