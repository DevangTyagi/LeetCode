class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto itr : nums) mpp[itr]++;
        for(auto itr : mpp) {
            if(itr.second % 2 != 0)
            return false;
        }
        return true;
    }
};