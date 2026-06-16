// OPTIMAL Approach 1
vector<int> generateRow(int row) {
    vector<int> temp;
    temp.push_back(1);
    long long ans = 1;
    for (int i = 1; i < row; i++) {
        ans = ans * (row - i);
        ans = ans / i;
        temp.push_back(ans);
    }
    return temp;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};

// OPTIMAL Approach 2 (own) (O(N^2))
//  class Solution {
//  public:
//      vector<vector<int>> generate(int numRows) {
//          vector<vector<int>> ans;
//          if (numRows == 0) {
//              return ans;
//          } else if (numRows == 1) {
//              vector<int> result;
//              result.push_back(1);
//              ans.push_back(result);
//              return ans;
//          }

//         else if (numRows > 2) {
//             vector<int> row1;
//             row1.push_back(1);
//             ans.push_back(row1);

//             vector<int> row2;
//             row2.push_back(1);
//             row2.push_back(1);
//             ans.push_back(row2);

//             numRows = numRows - 2;
//         }

//         else if (numRows == 2) {
//             vector<int> row1;
//             row1.push_back(1);
//             ans.push_back(row1);

//             vector<int> row2;
//             row2.push_back(1);
//             row2.push_back(1);
//             ans.push_back(row2);
//             return ans;
//         }
//         int size = 3;
//         for (int i = 0; i < numRows; i++) {

//             vector<int> result(size, 0);

//             int left = 0;
//             int right = 1;

//             result[0] = 1;
//             result[size - 1] = 1;

//             vector<int> prev = ans[size - 2];
//             while (right < prev.size()) {
//                 long long sum = prev[left] + prev[right];
//                 result[right] = sum;

//                 left++;
//                 right++;
//             }
//             size++;
//             ans.push_back(result);
//         }

//         return ans;
//     }
// };