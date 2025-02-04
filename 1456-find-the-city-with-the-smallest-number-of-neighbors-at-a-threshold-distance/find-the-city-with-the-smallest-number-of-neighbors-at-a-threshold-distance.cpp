class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,1e9));
        int ans = 0; 
        int min_cities = n;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) 
                matrix[i][j]= 0;
            }
        }
        for(auto &itr : edges) {
            int from = itr[0];
            int to = itr[1];
            int cost = itr[2];
            matrix[from][to] = cost;
            matrix[to][from] = cost;
        }
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k]+matrix[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++) {
            int count = 0;
            for(int j=0;j<n;j++) {
                if(matrix[i][j] <= distanceThreshold)
                count++;
            }
            if(count != 0 && count <= min_cities) {
            ans = max(ans,i);
            min_cities = count;
            }

        }
        return ans;
    }
};