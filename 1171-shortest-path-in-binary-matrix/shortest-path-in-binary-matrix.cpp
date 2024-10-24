class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int ans = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
   
        if(grid[m-1][n-1] == 1 || grid[0][0] == 1)
        return -1;
        if (m == 1 && n == 1 && grid[0][0] == 0)
        return 1;

        int row[] = {-1,-1,0,1,1,1,0,-1};
        int col[] = {0,1,1,1,0,-1,-1,-1};  
        vector<vector<int>>visited(m,vector<int>(n,0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1,{0,0}});
        visited[0][0] = 1;
        while(!pq.empty()){
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(int i=0;i<8;i++){
                int nrow = row[i] + r;
                int ncol = col[i] + c;
                if(nrow == m-1 && ncol == n-1)
                return dis + 1;
                if(nrow < m && nrow >= 0 && ncol < n && ncol >=0 && !visited[nrow][ncol] && grid[nrow][ncol]==0)
                {
                    pq.push({dis + 1 , {nrow,ncol}});
                    visited[nrow][ncol]=1;
                }
            }

        }
        return -1;
    }
};