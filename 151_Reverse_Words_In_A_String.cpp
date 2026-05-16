class Solution {
public:
    string reverseWords(string s) {

        stack<string> st;
        string word = "";

        for(char c : s){

            if(c != ' '){
                word += c;
            }
            else{

                if(word != ""){
                    st.push(word);
                    word = "";
                }
            }
        }

        // Push last word
        if(word != ""){
            st.push(word);
        }

        string ans = "";

        while(!st.empty()){

            ans += st.top();
            st.pop();

            if(!st.empty()){
                ans += " ";
            }
        }

        return ans;
    }
};