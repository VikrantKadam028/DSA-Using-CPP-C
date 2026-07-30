class Solution {
public:
    int minimumPushes(string word) {
        //means for first 8 chars push 1, for the next 8 chars push 2 and so on....
       int result = 0;

       for(int i=0;i<word.length();i++){
        result += i / 8 + 1;
       }
       return result;
    }
};