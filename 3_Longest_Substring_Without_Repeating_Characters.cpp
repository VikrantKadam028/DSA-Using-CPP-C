class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        if (n == 0)
            return 0;

        int left = 0, right = 0;
        int longest = 0, maxi = 0;

        unordered_map<char, int> mp;

        while (right < n) {
            while (mp.find(s[right]) != mp.end()) {
                mp.erase(s[left]);
                longest--;
                left++;
            }

            mp[s[right]]++;
            longest++;

            maxi = max(maxi, longest);
            right++;
        }

        return maxi;
    }
};

// low eff. as right is going back after everytime break, but its works :).
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();

//         if (s.empty())
//             return 0;
//         if (n == 1)
//             return 1;

//         int left = 0;
//         int right = 0;
//         int longest = 0;
//         int maxi = INT_MIN;

//         unordered_map<char, int> mp;
//         while (right < n) {
//             if (mp.find(s[right]) != mp.end()) {
//                 longest = 0;
//                 left++;
//                 right = left;
//                 mp.clear();
//             }

//             mp[s[right]]++;

//             longest++;
//             maxi = max(maxi, longest);
//             right++;
//         }

//         return maxi;
//     }
// };