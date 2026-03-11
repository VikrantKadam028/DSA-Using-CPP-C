class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) return 1;

        string digits = bitset<32>(n).to_string();

        //get the posn of first 1 in the string.
        int pos = digits.find('1');

        //start from pos to the end.
        digits = digits.substr(pos);

        for(int i = 0; i < digits.length(); i++){
            digits[i] = (digits[i] == '0') ? '1' : '0';
        }

        return stoi(digits, 0, 2);
    }
};
