class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
         int champ = -1,count = 0;
         vector<int>indegree(n,0);
         for(auto &itr : edges){
            indegree[itr[1]]++;
        }
        for(int i=0;i<n;i++){
        if(indegree[i]==0){
            count++;
            champ = i;
        }
        }
        if(count != 1)
        return -1;
        return champ;
    }
};