class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for(int i=0;i<arr1.size();i++){
            int num= arr1[i];
            bool smaller = false;

            for(int j = 0;j<arr2.size();j++){
                if(abs(num - arr2[j]) <= d){
                    smaller = true;
                    break;
                }
            }

            if(!smaller){
                count++;
            }
        }

        return count;
    }
};