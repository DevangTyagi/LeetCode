class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&visited)
    {
        visited[node]=1;
        for(auto itr : adj[node])
        {
            if(!visited[itr])
            dfs(itr,adj,visited);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int v = isConnected.size();
        vector<int>adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>visited(v,0);
        int count=0;
        for(int i=0;i<v;i++){
            if(visited[i]==0)
            {
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};