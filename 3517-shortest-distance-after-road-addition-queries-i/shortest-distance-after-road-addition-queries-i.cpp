class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int>ans;
        vector<int>adj[n];        
        for(int i=0;i<n-1;i++)
        adj[i].push_back(i+1);
        for(auto &itr : queries){
        adj[itr[0]].push_back(itr[1]);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        vector<int>dist(n,1e9);
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            int node = pq.top().first;
            int d = pq.top().second;
            pq.pop();
            for(auto itr : adj[node]){
                if(dist[itr] > d + 1){
                    dist[itr] = d + 1;
                    pq.push({itr , d + 1});
                }
            }            
        }
        ans.push_back(dist[n-1]);
        }
        
        return ans;
    }
};