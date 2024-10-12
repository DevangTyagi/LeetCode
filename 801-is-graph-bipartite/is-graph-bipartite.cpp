class Solution {
private:
    bool Dfs(int node , int col , vector<vector<int>>& graph , vector<int>&color)
    {
       color[node] = col;
       for(auto itr : graph[node]){
        if(color[itr] == -1){
         if(Dfs(itr,!col,graph,color) == false)
         return false;
        }        
        else if(color[itr] == col)
        return false;
       }
       return true;
    } 
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i] == -1){
            if(Dfs(i,0,graph,color) == false)
            return false;
            }
        }
        return true;
    }
};