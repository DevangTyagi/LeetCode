class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
      priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
      vector<pair<int,int>>adj[n+1];
      vector<int>time(n+1,1e9);
      for(auto &itr : times){
        adj[itr[0]].push_back({itr[1],itr[2]}); // src -> {dst , time}
      }
      time[k] = 0;
      pq.push({0,k});
      while(!pq.empty()){
        int t = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int neighbour = it.first;
           if(time[neighbour] > t + it.second) {
            time[neighbour] = t + it.second;
            pq.push({time[neighbour] , neighbour});
           }
        }
      }
      int mintime = 0;
      for(int i=1;i<=n;i++){
        if(time[i] == 1e9)
        return -1;
        mintime = max(mintime,time[i]);
      }
      return mintime;
    }
};