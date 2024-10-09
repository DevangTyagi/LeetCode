class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int def_row[] = {-1,0,1,0};
        int def_col[] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            ans[r][c] = dis;
            q.pop();
            for(int i=0;i<4;i++){
                int row = r + def_row[i];
                int col = c + def_col[i];
                if(row >= 0 && row < m && col >= 0 && col < n && mat[row][col]==1 && vis[row][col] == 0)
                {
                    q.push({{row,col},dis+1});
                    vis[row][col] = 1;
                }
              }
        }
        return ans;        
    }
};