class Solution {
public:
    long long solve(int i,int j,vector<int>& robot,vector<int>& factory,vector<vector<long long>> &dp){
        if(i>=robot.size()) 
        return 0;
        if(j>=factory.size()) 
        return 1e18;
        if(dp[i][j]!=-1) 
        return dp[i][j];
        long long taken = abs(factory[j]-robot[i]) + solve(i+1,j+1,robot,factory,dp);
        long long not_taken = solve(i,j+1,robot,factory,dp);  // Skip the factory
        return dp[i][j]=min(taken,not_taken);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> factories;
        int r = robot.size();
        for(auto itr : factory){         //Expanding Factory array 
            for(int i=0 ; i < itr[1] ; i++) {
                factories.push_back(itr[0]);
            }
        }
        int f = factories.size();
        vector<vector<long long>> dp(r+1,vector<long long>(f+1,-1));
        return solve(0,0,robot,factories,dp);
    }
};