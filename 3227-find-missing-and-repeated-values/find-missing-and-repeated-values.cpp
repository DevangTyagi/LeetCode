class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mpp;
        int n = grid.size();
        for (auto& g_row : grid) {
            for (auto& g_col : g_row)
                mpp[g_col]++;
        }
        int extra = 0, missing = 0;
        for (int i = 1; i <= n * n; i++) {
            if (mpp[i] > 1)
                extra = i;
            if (mpp[i] == 0)
                missing = i;
        }
        return { extra, missing };
    }
};