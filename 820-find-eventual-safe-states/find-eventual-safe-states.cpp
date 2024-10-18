class Solution {
public:
    bool safe_check(int node , vector<vector<int>>& graph , vector<int>&visited , vector<int>&path_vis ,vector<int>&safe_node)
    {
      visited[node] = 1;
      path_vis[node] = 1;
      for(auto itr : graph[node]){
        if(!visited[itr])
        {
            if(safe_check(itr,graph,visited,path_vis,safe_node) == false)
            return false;
        }
        else if(path_vis[itr]==1)
        return false;
      }
      path_vis[node] = 0;
      safe_node.push_back(node);
      return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
      vector<int>visited(graph.size(),0);
      vector<int>path_vis(graph.size(),0);
      vector<int>safe_node;
      for(int i=0;i<graph.size();i++)
      {
        if(!visited[i]){
            safe_check(i,graph,visited,path_vis,safe_node);
        }
      } 
      sort(safe_node.begin(),safe_node.end());
      return safe_node;
    }
};