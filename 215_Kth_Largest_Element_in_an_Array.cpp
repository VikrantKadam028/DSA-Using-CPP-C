class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int n : nums) {
            pq.push(n);

            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {

//         sort(nums.begin(), nums.end());

//         stack<int> st;

//         st.push(nums[0]);
//         for(int i = 1; i < nums.size(); i++){
//             st.push(nums[i]);
//         }

//         int index = 0;
//         while(k--){
//             index = st.top();
//             st.pop();
//         }

//         return index;
//     }
// };

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         reverse(nums.begin(), nums.end());

//         return nums[k-1];

//     }
// };
