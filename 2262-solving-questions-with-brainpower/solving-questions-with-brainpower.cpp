class Solution {
public:
    vector<long long> memo;
    
    long long solve(vector<vector<int>>& questions, int i) {
        if (i >= questions.size()) return 0;
        if (memo[i] != -1) return memo[i];
        
        int next = i + questions[i][1] + 1;
        long long take = questions[i][0] + solve(questions, next);
        long long skip = solve(questions, i + 1);
        
        return memo[i] = max(take, skip);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        memo.resize(n, -1);
        return solve(questions, 0);
    }
};
