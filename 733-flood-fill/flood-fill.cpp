class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited( n , vector<int>(m)); 
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j]=image[i][j];
            }
        }
        int org_color = image[sr][sc];
        visited[sr][sc]=color;
        q.push({sr,sc});
        int def_row[] = {-1,0,1,0};
        int def_col[] = {0,1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int adj_row = row + def_row[i];
                int adj_col = col + def_col[i];
                if(adj_row >= 0 && adj_row < n && adj_col >= 0 && adj_col < m && visited[adj_row][adj_col] != color && visited[adj_row][adj_col] == org_color)
                {
                    q.push({adj_row,adj_col});
                    visited[adj_row][adj_col] = color;
                }
            }
        }
        return visited;
    }
};