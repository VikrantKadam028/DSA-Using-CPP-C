class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd_cnt = 0;
        int even_cnt = 0;

        for(int n : nums1){
            if(n % 2 == 0){
                even_cnt++;
            }else{
                odd_cnt++;
            }
        }

        if(odd_cnt >= 1) return true;
        if(even_cnt >= 1) return true;

        return false;
    }
};