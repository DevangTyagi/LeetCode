class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
       for(auto& currrow : matrix)
       {
        vector<int> rev(n);
        for(int col = 0 ; col < n ; col++){
            rev[col] = (currrow[col] == 0) ? 1 : 0;
        }
        int count = 0;
        for(auto &row : matrix){
            if(row == currrow || row == rev)
            count++;
        }
        ans = max(ans,count);
       } 
       return ans;
    }
};