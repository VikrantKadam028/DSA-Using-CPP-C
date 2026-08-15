class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        int longest = INT_MIN;

        unordered_map<char,int> mpp;

        while(r < s.length()){
            mpp[s[r]]++;
        
            while(mpp[s[r]] > 2){
                mpp[s[l]]--;
                l++;
            }

            longest = max(longest, r - l + 1);
            r++;
        }
        return longest;
    }
};