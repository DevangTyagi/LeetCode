class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vec;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(), vec.end());
        int med_idx = vec.size() / 2;
        int ans = 0;
        for (auto& itr : vec) {
            if (vec[med_idx] % x != itr % x) {
                return -1;
            }
            ans += (abs(vec[med_idx] - itr) / x);
        }
        return ans;
    }
};