class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        unordered_map<char,int>mpp;
        int odd_char = 0;        
        if(s.size() < k)
        return false;
        if(s.size() == k)
        return true;
        for(auto &itr : s) 
        mpp[itr]++;
        for(auto &itr : mpp) {
          if(mpp[itr.first]%2 != 0)
           odd_char++;
        }
        return (odd_char <= k);
    }
};