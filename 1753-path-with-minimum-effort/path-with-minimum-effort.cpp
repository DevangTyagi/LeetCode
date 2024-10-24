class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;       
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            int effort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();            
            if (r == m - 1 && c == n - 1)
            return effort;         
            for (int i = 0; i < 4; i++) {
                int nrow = r + row[i];
                int ncol = c + col[i];                
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    int newEffort = max(effort, abs(heights[nrow][ncol] - heights[r][c]));                    
                    if (newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }       
        return -1;
    }
};
