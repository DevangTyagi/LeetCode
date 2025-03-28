class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> ans;
        int m = grid.size(), n = grid[0].size();
        vector<int> sorted_query = queries;
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        unordered_map<int, int> mpp;
        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};
        int count = 0;
        sort(sorted_query.begin(), sorted_query.end());
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        for (int i = 0; i < sorted_query.size(); i++) {
            int query = sorted_query[i];

            while (!pq.empty() && pq.top().first < query) {
                count++;
                int r = pq.top().second.first;
                int c = pq.top().second.second;
                pq.pop();
                for (int j = 0; j < 4; j++) {
                    int n_row = r + row[j];
                    int n_col = c + col[j];
                    if (n_row >= 0 && n_row < m && n_col >= 0 && n_col < n &&
                        vis[n_row][n_col] != 1 ) {
                        vis[n_row][n_col] = 1;
                        pq.push({grid[n_row][n_col],{n_row, n_col}});
                    }
                }
            }
            mpp[query] = count;
        }
        for(auto itr : queries)
        ans.push_back(mpp[itr]);
        return ans;
    }
};