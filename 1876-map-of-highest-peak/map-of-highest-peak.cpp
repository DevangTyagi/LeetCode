class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> heights(m,vector<int>(n,0));
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        int def_row[] = {0,1,0,-1};
        int def_col[] = {1,0,-1,0};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int n_row = row + def_row[j];
                int n_col = col + def_col[j];
                if(n_row >= 0 && n_row<m && n_col>=0 && n_col < n && visited[n_row][n_col] != 1){
                    visited[n_row][n_col] = 1;
                    heights[n_row][n_col] = heights[row][col] + 1;
                    q.push({n_row,n_col});
                }
          }
        }
        return heights;
    }
};