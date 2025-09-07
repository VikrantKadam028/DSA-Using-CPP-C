class Solution {
public:

    int countDigits(int num){
        int count = 0;
        if(num == 0){
            return 1;
        }
        while(num>0){
            num /= 10;
            count++;
        }
        return count;
    }

    string padNum(int num, int maxLength){
        string s = to_string(num);
        while (s.length() < maxLength) {
            s = "0" + s;  
        }
        return s;
    }

    int generateKey(int num1, int num2, int num3) {
        // Step 1: find max length
        int d1 = countDigits(num1);
        int d2 = countDigits(num2);
        int d3 = countDigits(num3);
        int maxLength = max(d1,max(d2,d3));

        // Step 2: pad numbers
        string p1 = padNum(num1, maxLength); 
        string p2 = padNum(num2, maxLength); 
        string p3 = padNum(num3, maxLength); 

        // Step 3: build key by taking min digit at each position
        string keyStr = "";
        for(int i = 0; i < maxLength; i++){
            char c1 = p1[i];
            char c2 = p2[i];
            char c3 = p3[i];
            char minDigit = min(c1, min(c2, c3));
            keyStr += minDigit;
        }

        // Step 4: convert string to integer
        int key = stoi(keyStr);
        return key;
    }
};
