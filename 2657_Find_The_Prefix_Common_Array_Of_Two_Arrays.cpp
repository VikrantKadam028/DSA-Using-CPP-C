class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> C;
        vector<int> ForA;
        vector<int> ForB;
        int n = A.size();
        int limit = 0;
        while (limit < n) {
            // loop for A
            for (int i = 0; i <= limit; i++) {
                ForA.push_back(A[i]);
            }

            // loop for B
            for (int i = 0; i <= limit; i++) {
                ForB.push_back(B[i]);
            }
            int count = 0;

            for (int i = 0; i < ForA.size(); i++) {
                for (int j = 0; j < ForB.size(); j++) {
                    if (ForA[i] == ForB[j]) {
                        count++;
                        break;
                    }
                }
            }
            C.push_back(count);
            limit++;

            ForA.clear();
            ForB.clear();
        }

        return C;
    }
};