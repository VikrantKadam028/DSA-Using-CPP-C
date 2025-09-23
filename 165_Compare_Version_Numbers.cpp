class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;

        string temp = "";
        for(char c: version1){
            if(c == '.'){
                v1.push_back(stoi(temp));
                temp = "";
            }else{
                temp += c; 
            }
        }
        if(!temp.empty()) v1.push_back(stoi(temp));

        temp = "";
        for(char c: version2){
            if(c == '.'){
                v2.push_back(stoi(temp)); 
                temp = "";
            }else{
                temp += c; 
            }
        }
        if(!temp.empty()) v2.push_back(stoi(temp)); 

        // compare
        int n = max(v1.size(), v2.size());
        for(int i=0;i<n;i++){
            int num1 = (i < v1.size() ? v1[i] : 0);
            int num2 = (i < v2.size() ? v2[i] : 0);

            if(num1 < num2) return -1;
            if(num1 > num2) return 1;
        }
        return 0;
    }
};
