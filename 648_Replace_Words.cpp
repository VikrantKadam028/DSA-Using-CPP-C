class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<char, vector<string>> mpp;
        string result = "";

        // put the first char and corresponding all its strings from dic that
        // starts with same char.
        for (int i = 0; i < dictionary.size(); i++) {
            string str = dictionary[i];

            mpp[str[0]].push_back(str);
        }

        // sort by length
        for (auto& it : mpp) {
            sort(it.second.begin(), it.second.end(),
                 [](string& a, string& b) { return a.size() < b.size(); });
        }

        int j = 0;
        while (j < sentence.length()) {
            string temp = "";

            // build the string from sentence str given.
            while (j < sentence.length() && sentence[j] != ' ') {
                temp += sentence[j];
                j++;
            }

            // move forward from whitespace.
            if (j < sentence.length()) {
                j++;
            }

            bool isfound = false;
            string newstr = "";

            // check if the temp first char key exist in the map, if yes then
            // traverse that key's vector, and find the one root that matches
            // the first char & prefix of temp.
            if (mpp.find(temp[0]) != mpp.end()) {
                for (string& root : mpp[temp[0]]) {
                    // check prefix, we want the root to be same as the starting
                    // of temp string. so use substr().
                    if (temp.substr(0, root.size()) == root) {
                        isfound = true;
                        newstr = root;
                        break;
                    }
                }
            }

            if (isfound) {
                result += newstr;
            } else {
                result += temp;
            }

            //add whitespace after each word build.
            if (j < sentence.length()) {
                result += ' ';
            }
        }
        return result;
    }
};