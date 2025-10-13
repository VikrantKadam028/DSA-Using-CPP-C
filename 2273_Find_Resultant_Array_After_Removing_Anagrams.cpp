class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> anagrams;
        anagrams.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            string prev = anagrams.back();
            string current = words[i];
            sort(prev.begin(), prev.end());
            sort(current.begin(), current.end());
            if (prev != current) {
                anagrams.push_back(words[i]);
            }
        }

        return anagrams;
    }
};
