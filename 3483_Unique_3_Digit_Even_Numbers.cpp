class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st;

        for (int i = 0; i < digits.size(); i++) {
            string str = "";
           
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {
                    str += to_string(digits[i]);
                    str += to_string(digits[j]);
                    str += to_string(digits[k]);

                    if (i != j && j != k && i != k &&
                        str.length() == 3 &&
                        str[0] != '0' &&
                        stoi(str) % 2 == 0) {

                        st.insert(stoi(str));
                    }

                    str = "";
                }
            }
        }

        return st.size();
    }
};