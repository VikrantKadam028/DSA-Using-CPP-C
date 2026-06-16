class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (char c : s) {
            if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (c == '#') {
                string dup = result;
                result += dup;
            } else if (c == '%') {
                int left = 0;
                int right = result.length() - 1;

                while (left < right) {
                    char temp = result[left];
                    result[left] = result[right];
                    result[right] = temp;

                    left++;
                    right--;
                }
            } else {
                result += c;
            }
        }
        return result;
    }
};