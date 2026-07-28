class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        vector<int> lastSeen(3, -1);

        for(int i=0;i<n;i++){
            lastSeen[s[i] - 'a'] = i;

            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                cnt += min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1;
            }
        }
        return cnt;
    }
};

/* 
class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int result = 0;
        int n = s.length();

        while (j < s.length()) {

            char ch = s[j];
            mp[s[j]]++;

            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                result += (n - j);
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return result;
    }
};
*/