class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(int i = 0;i<s.length();i++){
            if(s[i] == '*'){
                st.pop();
            }else {
                st.push(s[i]);
            }
        }

        string result = "";

        while(!st.empty()){
            char str = st.top();
            result += str;
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};