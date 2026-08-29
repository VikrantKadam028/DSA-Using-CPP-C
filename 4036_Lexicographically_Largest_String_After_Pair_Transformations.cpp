class Solution {
public:
    vector<string> largestString(vector<int>& nums) {

        vector<string> vec;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            string result = "";
            int idx = 0;
            while (num > 0) {
                int no = num % 2;
                if(idx >= 26){
                    result += "zz";
                }
                else if (no == 1) {
                    result += (char)('a' + idx);
                }
                idx++;
                num /= 2;
            }
            reverse(result.begin(), result.end());
            vec.push_back(result);
        }

        return vec;
    }
};