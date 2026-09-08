class Solution {
public:
    int countCommas(int n) {
        if(to_string(n).length() < 4 ){
            return 0;
        }

        int cnt = 0;

        for(int i=1;i<=n;i++){
            string str = to_string(i);

            if(str.length() >= 4){
                if(str.length() == 4 || str.length() == 5 || str.length() == 6){
                    cnt += 1;
                }else if(str.length() == 7 || str.length() == 8 || str.length() == 9){
                    cnt += 2;
                }
            }
        }
        return cnt;
    }
};