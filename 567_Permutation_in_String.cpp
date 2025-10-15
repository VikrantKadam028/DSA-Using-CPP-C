class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m)
            return false;

        string sorted_s1 = s1;
        sort(sorted_s1.begin(), sorted_s1.end());

        for (int i = 0; i <= m - n; i++) {
            string sub = s2.substr(i, n);
            sort(sub.begin(), sub.end());
            if (sub == sorted_s1)
                return true;
        }

        return false;
    }
};
