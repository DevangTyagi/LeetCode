class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int>row_sum(grid.size(),0);
        vector<int>col_sum(grid[0].size(),0);
        int total_server = 0;
        int isolated = 0;
        for(int i=0;i<grid.size();i++){
            row_sum[i] = accumulate(grid[i].begin(),grid[i].end(),0);
        }
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = 0; i < grid.size(); i++) {
              col_sum[j] += grid[i][j];
            }
        }
        for (auto &row : grid){
           for (int val : row){ 
               if (val == 1) {
               total_server++;
            }
         }
}
        for(int i =0 ;i <grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] != 0 && row_sum[i] == 1 && col_sum[j]==1)
                isolated++;
            }
        }
        return total_server - isolated;
    }
};