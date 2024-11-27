class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
       for (auto& road : roads) {
            adj[road[0]].emplace_back(road[1], road[2]);
            adj[road[1]].emplace_back(road[0], road[2]);
        }
      priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>>pq;
      vector<long long>time(n,LLONG_MAX);
      vector<long long>ways(n,0);
      time[0] = 0;
      ways[0] = 1;
      pq.push({0,0});
      while(!pq.empty()){
        long long t = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (t > time[node]) 
        continue;
        for(auto it : adj[node]){
            int neighbour = it.first;
           if(time[neighbour] > t + it.second) {
            time[neighbour] = t + it.second;
            ways[neighbour] = ways[node];
            pq.push({time[neighbour] , neighbour});
           }
           else if(time[neighbour] == t + it.second)
           ways[neighbour] = (ways[neighbour] + ways[node]) % MOD;
        }
      }
    return ways[n-1];
    }
};