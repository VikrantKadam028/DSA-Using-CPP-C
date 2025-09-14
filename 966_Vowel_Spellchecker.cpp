class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exactSet(wordlist.begin(), wordlist.end());
        unordered_map<string, string> CaseMap;
        unordered_map<string, string> VowelMap;
        vector<string> result;
\
        for (int i = 0; i < wordlist.size(); i++) {
            string lower = toLower(wordlist[i]);

            if (CaseMap.find(lower) == CaseMap.end()) {
                CaseMap[lower] = wordlist[i];
            }

            string dev = devowel(lower);
            if (VowelMap.find(dev) == VowelMap.end()) {
                VowelMap[dev] = wordlist[i];
            }
        }

        for (int j = 0; j < queries.size(); j++) {
            if (exactSet.find(queries[j]) != exactSet.end()) {
                result.push_back(queries[j]);
            } else {
                string lower = toLower(queries[j]);
                auto it = CaseMap.find(lower);
                if (it != CaseMap.end()) {
                    result.push_back(it->second);
                } else {
                    string dev = devowel(lower);
                    auto it2 = VowelMap.find(dev);
                    if (it2 != VowelMap.end()) {
                        result.push_back(it2->second);
                    } else {
                        result.push_back("");
                    }
                }
            }
        }

        return result; 
    }

private:
    string toLower(string s) {
        for (char& c : s) {
            c = tolower(c);
        }
        return s;
    }

    string devowel(string s) {
        for (char& c : s) {
            if (isVowel(c))
                c = '*';
        }
        return s;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

