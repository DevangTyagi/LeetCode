class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) { 
        parent[y] = x;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges,vector<vector<int>>& query) {
        parent.resize(n);
        vector<int>cost(n,-1);
        for(int i=0;i<n;i++)
        parent[i] = i;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            int parent_u = find(u);
            int parent_v = find(v);
            if(parent_u != parent_v) {
             Union(parent_u,parent_v);
             cost[parent_u] &= cost[parent_v];
            }
            cost[parent_u] &= w;
         }
         vector<int>ans;
         for(auto it : query) {
            int a = it[0];
            int b = it[1];
            if(a == b)
            ans.push_back(0);
            else if(find(a) != find(b)) 
            ans.push_back(-1);
            else
            ans.push_back(cost[find(a)]);
         }
         return ans;
    }
};