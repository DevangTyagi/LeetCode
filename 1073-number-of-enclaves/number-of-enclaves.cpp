class Solution {
private:
void dfs_mark(int row , int col , vector<vector<int>>&visited , vector<vector<int>>& grid,int def_row[],int def_col[])
   {
     visited[row][col] = 1;
     int m = grid.size();
     int n = grid[0].size();
     for(int i=0;i<4;i++)
     {
        int r = row + def_row[i];
        int c = col + def_col[i];
        if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1 && visited[r][c] == 0){
           dfs_mark(r,c,visited,grid,def_row,def_col);
        }
     }
     return;
   }
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int def_row[] = {-1,0,1,0};
        int def_col[] = {0,1,0,-1};
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++)
        {
            if(grid[i][0] == 1 && visited[i][0] == 0){
                dfs_mark(i,0,visited,grid,def_row,def_col);
            }
            if(grid[i][n-1] == 1 && visited[i][n-1] == 0){
                dfs_mark(i,n-1,visited,grid,def_row,def_col);
            }
        }
        for(int j = 0 ; j < n ; j++)
        {
            if(grid[0][j] == 1 && visited[0][j] == 0){
                dfs_mark(0,j,visited,grid,def_row,def_col);
            }
            if(grid[m-1][j] == 1 && visited[m-1][j] == 0){
                dfs_mark(m-1,j,visited,grid,def_row,def_col);
            }
        } 

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == 0 && grid[i][j] == 1)
                count++;
            }
        }
        return count;
    }
};