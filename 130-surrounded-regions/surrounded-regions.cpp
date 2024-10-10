class Solution {
private:
   void dfs_mark(int row , int col , vector<vector<int>>&visited , vector<vector<char>>& board,int def_row[],int def_col[])
   {
     visited[row][col] = 1;
     int m = board.size();
     int n = board[0].size();
     for(int i=0;i<4;i++)
     {
        int r = row + def_row[i];
        int c = col + def_col[i];
        if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O' && visited[r][c] == 0){
           dfs_mark(r,c,visited,board,def_row,def_col);
        }
     }
     return;
   }
public:
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        int def_row[] = {-1,0,1,0};
        int def_col[] = {0,1,0,-1};
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++)
        {
            if(board[i][0] == 'O' && visited[i][0] == 0){
                dfs_mark(i,0,visited,board,def_row,def_col);
            }
            if(board[i][n-1] == 'O' && visited[i][n-1] == 0){
                dfs_mark(i,n-1,visited,board,def_row,def_col);
            }
        }
        for(int j = 0 ; j < n ; j++)
        {
            if(board[0][j] == 'O' && visited[0][j] == 0){
                dfs_mark(0,j,visited,board,def_row,def_col);
            }
            if(board[m-1][j] == 'O' && visited[m-1][j] == 0){
                dfs_mark(m-1,j,visited,board,def_row,def_col);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == 0 && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};