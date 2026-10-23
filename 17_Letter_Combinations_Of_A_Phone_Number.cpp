class Solution {
public:
    void func(string& digits, vector<string>& res, int n, int idx,
              string& diary, unordered_map<char, string> mpp) {
        if (idx == n) {
            res.push_back(diary);
            return;
        }

        string choice = mpp[digits[idx]];

        for (int i = 0; i < choice.length(); i++) {
            diary.push_back(choice[i]);

            func(digits, res, n, idx + 1, diary, mpp);

            diary.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string diary = "";

        unordered_map<char, string> mpp = {
            {'1', "0"},    {'2', "abc"}, {'3', "def"},
            {'4', "ghi"},  {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        func(digits, res, digits.length(), 0, diary,mpp);

        return res;
    }
};