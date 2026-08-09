class Solution {
public:
    vector<vector<int>> children;
    vector<int> depth;
    vector<int> height;
    void dfs(int u, int parent, int d) {
        depth[u] = d;

        for (int v : children[u]) {
            if (v == parent) {
                continue;
            }

            dfs(v, u, d + 1);

            height[u] = max(height[u], 1 + height[v]);
        }
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        children.resize(n);
        depth.resize(n);
        height.resize(n);
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] != -1) {
                children[parent[i]].push_back(i);
            }
        }

        int root = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == -1) {
                root = i;
                break;
            }
        }

        dfs(root, -1, 0);
        long long maxHeight = *max_element(height.begin(), height.end());

        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] * (maxHeight - depth[i] + 1);
        }

        return sum;
    }
};