class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for(int i=0;i<patterns.size();i++){
            string str = patterns[i];

            if(word.contains(str)) cnt++;
        }

        return cnt;
    }
};