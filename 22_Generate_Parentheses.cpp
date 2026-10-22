class Solution {
public:
    void func(int open, int close, int n, string &temp, vector<string> &res){
        if(open == n && close == n){
            res.push_back(temp);
            return;
        }

        if(open < n){
            temp.push_back('(');
            func(open+1, close, n, temp,res);
            temp.pop_back();
        }

        if(close < open){
            temp.push_back(')');
            func(open, close+1, n , temp, res);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> str;

        string temp = "";

        func(0,0,n, temp,str);

        return str;
    }
};