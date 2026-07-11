class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        unordered_map<char,int> common;

        for(char c : words[0])
            common[c]++;

        for(int i=1;i<words.size();i++)
        {
            unordered_map<char,int> freq;

            for(char c: words[i])
                freq[c]++;

            for(auto it = common.begin(); it != common.end(); )
            {
                if(freq.find(it->first)==freq.end())
                {
                    it = common.erase(it);   
                }
                else
                {
                    it->second = min(it->second, freq[it->first]);
                    ++it;
                }
            }
        }

        vector<string> ans;

        for(auto &it: common)
        {
            while(it.second--)
            {
                ans.push_back(string(1,it.first));
            }
        }

        return ans;
    }
};