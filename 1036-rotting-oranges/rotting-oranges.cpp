class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int visited[m][n];
        queue<pair<pair<int,int>,int>>q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==2)
               {
                q.push({{i,j},0});
                visited[i][j]=1;
               }
               else{
                visited[i][j]=0;
               }
               if(grid[i][j]==1)
               fresh++;
            }
        }
        int tm = 0;
        int def_row[] = {-1,0,1,0};
        int def_col[] = {0,1,0,-1};

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int row = r + def_row[i];
                int col = c + def_col[i];
                if(row >= 0 && row < m && col >= 0 && col < n && visited[row][col]==0 && grid[row][col]==1){
                    q.push({{row,col},t+1});
                    visited[row][col] = 1;
                    fresh--;
                }
            }
        }

        if(fresh != 0) return -1;

        return tm;
    }
};