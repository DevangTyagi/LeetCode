class Solution {
public:
    vector<vector<int>> Merge(vector<vector<int>> X) {
       vector<vector<int>>ans;
       sort(X.begin(),X.end());
       ans.push_back(X[0]);
       for(auto itr : X) {
        if(ans.back()[1] > itr[0]) {
            ans.back()[1] = max(ans.back()[1],itr[1]);
        } else {
            ans.push_back(itr);
        }
       }
       return ans;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> X;
        vector<vector<int>> Y;
        for (auto itr : rectangles) {
            int x1 = itr[0];
            int y1 = itr[1];
            int x2 = itr[2];
            int y2 = itr[3];
            X.push_back({x1,x2});
            Y.push_back({y1,y2});
        }
        vector<vector<int>>X_unq = Merge(X);
        if(X_unq.size() >= 3)
        return true;
        vector<vector<int>>Y_unq = Merge(Y);
        return Y_unq.size() >= 3;
    }
};