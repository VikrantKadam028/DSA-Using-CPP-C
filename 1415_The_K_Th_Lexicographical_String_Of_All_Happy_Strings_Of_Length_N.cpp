class Solution {
public:
    void func(int n, string s, vector<string>& nums, string& temp, int idx) {
        if (temp.size() == n) {
            nums.push_back(temp);
            return;
        }

        for (int i = 0; i < s.length(); i++) {

            if (temp.empty() || s[i] != temp.back()) {

                temp.push_back(s[i]);

                func(n, s, nums, temp, idx + 1);

                temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string str = "abc";
        vector<string> nums;

        string temp = "";
        func(n, str, nums, temp, 0);

        if (k > nums.size()) return "";

        return nums[k - 1];
    }
};