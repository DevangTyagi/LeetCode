class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
      vector<int>dist(n,1e9);
      // {stops , node , cost}
      queue< pair<int , pair<int,int>>> q;
      vector<pair<int,int>>adj[n];
      for(auto &itr : flights){
        adj[itr[0]].push_back({itr[1],itr[2]});
        // {node , cost}
      }
      q.push({0,{src,0}});
      dist[src] = 0;
      while(!q.empty())
      {
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        if(stops > k)
        continue;
        for(auto itr : adj[node])
        {
          int adj_node = itr.first;
          int new_dis = itr.second;
          if(new_dis + cost < dist[adj_node] ){
            dist[adj_node] = new_dis + cost;
            q.push({stops + 1 , { adj_node , new_dis + cost }});
          }
        }
      }
      if(dist[dst] == 1e9) return -1;
      return dist[dst];
    }
};