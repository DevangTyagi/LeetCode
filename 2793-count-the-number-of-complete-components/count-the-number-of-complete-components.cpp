class Solution {
public:
void Dfs(vector<vector<int>>&adj, vector<bool> &visited,int node ,int &v, int &e) {
    visited[node] = true;
    e += adj[node].size();
    v++;
    for(auto itr : adj[node]) {
        if(!visited[itr]) {
            Dfs(adj,visited,itr,v,e);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, 0);
        int res = 0;
        vector<vector<int>>adj(n);
        for(auto& itr : edges) {
            int u = itr[0];
            int v= itr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            int v = 0, e = 0;
            if (!visited[i]) {
                Dfs(adj,visited,i,v,e); 
                if (v*(v - 1) == e) 
                res++;
            }
        }
        return res;
    }
};