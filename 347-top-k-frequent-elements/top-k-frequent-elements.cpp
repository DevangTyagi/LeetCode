class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int,int>mpp;
        int n = nums.size();
        vector<int>ans;
        for(auto itr : nums) mpp[itr]++;
        vector<vector<int>>temp(n+1); // As n+1 may be the highest frequency of a element 
        for(auto itr : mpp)
        {
            temp[itr.second].push_back(itr.first);
        }
        for(int i=n;i>=0;i--)
        {
        if(temp[i].empty()) continue;
          while(k>0 && !temp[i].empty()){
            ans.push_back(temp[i].back());
            temp[i].pop_back();
            k--;
          }
        }
        return ans;
    }
};