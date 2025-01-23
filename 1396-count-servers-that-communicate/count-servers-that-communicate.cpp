class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int>row_sum(grid.size(),0);
        vector<int>col_sum(grid[0].size(),0);
        int isolated = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    row_sum[i]++;
                    col_sum[j]++;
                }
            }
       }		
        for(int i =0 ;i <grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] != 0 && (row_sum[i] > 1 || col_sum[j] > 1))
                isolated++;
            }
        }
        return isolated;
    }
};